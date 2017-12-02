#include <atmel_start.h>
int main(void)
{
	struct adc_sync_descriptor volatile mic;
	struct io_descriptor  *i2c0;
	struct i2c_m_sync_desc SPEAKER;

	volatile int i,j;
	volatile int x;
	volatile int maxIndex = 0;
	volatile int next =0;
	volatile double max = 0;
	volatile double nu = 0.1;
	volatile double en = 0; 
	volatile double phase;
	volatile double frequency = 1470.0/ 7.0;
	volatile double t = 1470.0;
	volatile double signal[MAXSAMPLE] = {0};
	volatile double found[MAXSAMPLE] = {0};

	static volatile double ww[3][MAXSAMPLE];
	static volatile double final[MAXSAMPLE] = {0};
	
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	i2c_m_sync_init(&i2c0, FLEXCOM3);
	adc_sync_init(&mic, ADC, (void *)NULL);
	adc_sync_enable_channel(&mic, CONF_ADC_0_CHANNEL_0);

	i2c_m_sync_get_io_descriptor(&SPEAKER, &i2c0);
	i2c_m_sync_enable(&SPEAKER);
	i2c_m_sync_set_slaveaddr(&SPEAKER, 0x61, I2C_M_SEVEN);
	
	delay_ms(500);
	
	//Initialized the weight
	for (i =0; i < 3; i++)
		for (j=0; j <MAXSAMPLE; j++)
			ww[i][j] = 0.0; 
	//Sample the audio 
	for (i = 0; i < MAXSAMPLE; i++){
		volatile uint8_t buffer_ch0[2];
		volatile int16_t rx;
		adc_sync_read_channel(&ADC_0, CONF_ADC_0_CHANNEL_0, buffer_ch0, 2);
		rx  =buffer_ch0[0] + (buffer_ch0[1] << 8);
		//rx = 2047+2047*cos(2.*M_PI*i/7 + M_PI/4);
		rx &= 0x0fff;
		signal[i] = ((double ) rx) ;
		if ((int)(signal[i]) > (int)(max)){
			max = signal[i];
			maxIndex = i;
		}
	}

	//Find the next occurrence of the peak
	for (i = maxIndex +1; i< MAXSAMPLE; i++){
		if ((signal[i]) == (signal[i] )){
			next = i;
			break;
		}
	}
	//Find the following occurance of the peak
	for(i = next + 1; i <MAXSAMPLE; i++)
		if (signal[i] >=(max - 0.005 * 4095) && signal[i] <=(max + 0.005 * 4095))
			break;
			
	//Develop the parameter of the signal 
	frequency = 1/((double)(i - next +1)/ 1470);
	x = (int) (1470.0/ (2.0 *frequency));
	en = acos(-1* (signal[x-1]/(max/2) -1));
	phase = en < 0 ? en *-.5 : x * .5;	
	
	//Recreate the signal
	for (i = 0; i <MAXSAMPLE; i++){
		found[i] = max/2 * cos(2*M_PI * frequency * (double)i/ t + phase ) + max/2;
	}
	//Develop the weight
	for (i = 2; i < MAXSAMPLE ; i++){
		
		en=found[i]-ww[0][i]*found[i]-ww[1][i]*found[i-1]-ww[2][i ]*found[i-2];//ERROR SGNAL S-(S+E)
		nu=2*(found[i] *found[i]+found[i-1] * found[i-1]+found[i-2] * found[i-2]);//STEP SIZE USED
		nu=1/nu;

		//CALCULATING WEIGHTS
		ww[0][i+1]=(ww[0][i]+nu*en*found[i]);
		ww[1][i+1]=ww[1][i]+nu*en*found[(i-1)];
		ww[2][i+1]=(ww[2][i]+nu*en*found[(i-2)]);
	}
	for (i =0; i < MAXSAMPLE; i++)
	{
		final[i] =  -1* ww[0][MAXSAMPLE -1] * found[i] ;
		if ( i > 0)
			final[i] -= ww[2][MAXSAMPLE -1] * found[i -1];
		if (i > 1)
			final[i] -= ww[2][MAXSAMPLE-1] *found[i-2];
		final[i] += max;
		final[i] = max - final[i];
	}
	i = 0;
	//Output the signal
	i2c0 += 0;
	while(1){
		volatile uint8_t buffer_ch0[2];
		volatile double rx;
		volatile uint8_t tx[2];
		
		adc_sync_read_channel(&mic, CONF_ADC_0_CHANNEL_0, buffer_ch0, 2);
		rx = (double)( buffer_ch0[0] + (buffer_ch0[1] << 8));
		found[i] = rx;
		final[i] =  -1* ww[0][MAXSAMPLE -1] * rx;
		if ( i == 0)
			final[i] -= ww[2][MAXSAMPLE -1] * found[MAXSAMPLE -1] - ww[2][MAXSAMPLE-1] *found[MAXSAMPLE-2];;
		if (i == 1)
			final[i] -= ww[2][MAXSAMPLE -1] * found[0] - ww[2][MAXSAMPLE-1] *found[MAXSAMPLE-1];
		else
			final[i] -= ww[2][MAXSAMPLE -1] * found[i-1] - ww[2][MAXSAMPLE-1] *found[MAXSAMPLE-1];
		final[i] += max;
		final[i] = max - final[i];
		if (i %2 == 0)
						{
							tx[0] = 0x0f;
							tx[1] = 0xff;
						}
		else
						{
							tx[0] = 0x00;
							tx[1] = 0x00;
						}
		io_write(i2c0, tx, 2);

		i++; 
		if (i == MAXSAMPLE)
	    i = 0; 
	}
}

void HardFault_Handler()
{
	volatile int a;
	a =  SCB->CFSR;
	__ASM volatile("BKPT #01");
	while(1);
}