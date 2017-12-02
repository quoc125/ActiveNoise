/* Auto-generated config file hpl_adc_config.h */
#ifndef HPL_ADC_CONFIG_H
#define HPL_ADC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Basic Configuration

// <o> Conversion Result Resolution

// <0=>12-bit
// <1=>13-bit
// <2=>14-bit
// <3=>15-bit
// <4=>16-bit
// <i> Defines the bit resolution for the ADC sample values
// <id> adc_emr_osr
#ifndef CONF_ADC_EMR_OSR
#define CONF_ADC_EMR_OSR 0
#endif

// <e> Trigger Enable
// <i> Hardware triggers are disabled. Starting a conversion is only possible by software.
// <id> adc_mr_trgen
#ifndef CONF_ADC_MR_TRGEN
#define CONF_ADC_MR_TRGEN 0
#endif

// <o> Trigger Selection
// <0=>External trigger
// <1=>TIOA0 Output of the Timer Counter Channel 0
// <2=>TIOA1 Output of the Timer Counter Channel 1
// <3=>TIOA2 Output of the Timer Counter Channel 2
// <4=>RTC OUT0
// <5=>RTT 16-Bit prescaler output
// <6=>RTT Event
// <i> These bits define the trigger selection.
// <id> adc_mr_trgsel
#ifndef CONF_ADC_MR_TRGSEL
#define CONF_ADC_MR_TRGSEL 0
#endif

// </e>

// <o> Sleep Mode
// <0=>Normal Mode: The ADC core and reference voltage circuitry are kept ON between conversions
// <1=>Sleep Mode: The wake-up time can be modified by programming FWUP(Fast Wake-up) bit
// <id> adc_mr_sleep
#ifndef CONF_ADC_MR_SLEEP
#define CONF_ADC_MR_SLEEP 0
#endif

// <o> Fast Wake Up
// <0=>Both ADC core and reference voltage circuitry are OFF between conversions
// <1=>Fast Wake-up Sleep mode, The voltage reference is ON between conversions and ADC core is OFF
// <id> adc_mr_fwup
#ifndef CONF_ADC_MR_FWUP
#define CONF_ADC_MR_FWUP 0
#endif

// <q> Free Running Mode
// <i> When enabled, the ADC is in free running mode and a new conversion
// <i> will be initiated when a previous conversion completes.
// <id> adc_mr_freerun
#ifndef CONF_ADC_MR_FREERUN
#define CONF_ADC_MR_FREERUN 0
#endif

// <o> Startup Time
// <0=>0 periods of ADCCLK
// <1=>8 periods of ADCCLK
// <2=>16 periods of ADCCLK
// <3=>24 periods of ADCCLK
// <4=>64 periods of ADCCLK
// <5=>80 periods of ADCCLK
// <6=>96 periods of ADCCLK
// <7=>112 periods of ADCCLK
// <8=>512 periods of ADCCLK
// <9=>576 periods of ADCCLK
// <10=>640 periods of ADCCLK
// <11=>704 periods of ADCCLK
// <12=>768 periods of ADCCLK
// <13=>832 periods of ADCCLK
// <14=>896 periods of ADCCLK
// <15=>960 periods of ADCCLK
// <id> adc_mr_startup
#ifndef CONF_ADC_MR_STARTUP
#define CONF_ADC_MR_STARTUP 4
#endif

// <o> Transfer Period <0-3>
// <i> The TRANSFER field should be set to 2 to guarantee the optimal transfer time.
// <id> adc_mr_transfer
#ifndef CONF_ADC_MR_TRANSFER
#define CONF_ADC_MR_TRANSFER 2
#endif

// <o> Prescaler Rate Selection <0-255>
// <i> The ADC uses the ADC clock (ADCCLK) to perform conversions.
// <i> The ADC clock 
// is selected in the PRESCAL field of ADC_MR.
// <i> ADCCLK = (Peripheral clock)/((PRESCAL + 1) * 2)

// <id> adc_emr_prescaler
#ifndef CONF_ADC_MR_PRESCAL
#define CONF_ADC_MR_PRESCAL 0
#endif

// </h>

// <e> Advanced Configuration
// <id> adc_advanced_settings
#ifndef CONF_ADC_ADVANCED
#define CONF_ADC_ADVANCED 0
#endif

// <o> Comparison Mode
// <0=>LOW: Generates an event when the converted data is lower than the low threshold of the window
// <1=>HIGH: Generates an event when the converted data is higher than the high threshold of the window
// <2=>IN: Generates an event when the converted data is in the comparison window
// <3=>OUT: Generates an event when the converted data is out of the comparison window
// <id> adc_emr_cmpmode
#ifndef CONF_ADC_EMR_CMPMODE
#define CONF_ADC_EMR_CMPMODE 0
#endif

// <o> Compare Window Lower Threshold <0-65535>
// <i> These bits define the lower threshold value.
// <id> adc_lccwr_lowthres
#ifndef CONF_ADC_LOWTHRES
#define CONF_ADC_LOWTHRES 0
#endif

// <o> Compare Window Upper Threshold <0-65535>
// <i> These bits define the lower threshold value.
// <id> adc_lccwr_highthres
#ifndef CONF_ADC_HIGHTHRES
#define CONF_ADC_HIGHTHRES 0
#endif

// <o> Comparison Type
// <0=> Any conversion is performed and comparison function drives the COMPE flag
// <1=> Comparison conditions must be met to start the storage of all conversions until the CMPRST bit is set
// <id> adc_emr_cmptype
#ifndef CONF_ADC_EMR_CMPTYPE
#define CONF_ADC_EMR_CMPTYPE 0
#endif

// <o> Comparison Selected Channel
// <0=>Channel 0
// <1=>Channel 1
// <2=>Channel 2
// <3=>Channel 3
// <4=>Channel 4
// <5=>Channel 5
// <6=>Channel 6
// <7=>Channel 7
// <i> Indicates which channel has to be compared
// <id> adc_emr_cmpsel
#ifndef CONF_ADC_EMR_CMPSEL
#define CONF_ADC_EMR_CMPSEL 0
#endif

// <q> Comparison All Channel
// <i> Indicates wether all channel are compared
// <id> adc_emr_cmpall
#ifndef CONF_ADC_EMR_CMPALL
#define CONF_ADC_EMR_CMPALL 0
#endif

// <o> Compare Event Filtering <0-3>
// <i> Number of consecutive compare events necessary to raise the flag = CMPFILTER+1
// <i> When programmed to 0, the flag rises as soon as an event occurs.
// <id> adc_emr_cmpfilter
#ifndef CONF_ADC_EMR_CMPFILTER
#define CONF_ADC_EMR_CMPFILTER 0
#endif

// <o> Averaging on Single Trigger Event
// <0=> The average requests several trigger events
// <1=> The average requests only one trigger event
// <id> adc_emr_aste
#ifndef CONF_ADC_EMR_ASTE
#define CONF_ADC_EMR_ASTE 0
#endif

// <o> External Clock Selection
// <0=> The peripheral clock is the source for the ADC prescaler
// <1=> PMC_PCKx is the source clock for the ADC prescaler
// <id> adc_emr_srcclk
#ifndef CONF_ADC_EMR_SRCCLK
#define CONF_ADC_EMR_SRCCLK 0
#endif

// <o> TAG of the ADC_LDCR
// <0=> Sets CHNB field to zero in ADC_LCDR
// <1=> Appends the channel number to the conversion result in ADC_LCDR
// <id> adc_emr_tag
#ifndef CONF_ADC_EMR_TAG
#define CONF_ADC_EMR_TAG 0
#endif

// <o> Auto-test Modes
// <0=> No auto test
// <1=> Offset Error test
// <2=> Gain Error (high code) test
// <3=> Gain Error (low code) test
// <id> adc_acr_autotest
#ifndef CONF_ADC_ACR_AUTOTEST
#define CONF_ADC_ACR_AUTOTEST 0
#endif

// </e>

// <h> Channel Configuration

// <e> User Sequence Mode
// <i> When enabled, the sequence respects what is defined
// <id> adc_mr_useq
#ifndef CONF_ADC_MR_USEQ
#define CONF_ADC_MR_USEQ 0
#endif

// <o> User Sequence Number 1
// <0=>Channel 0
// <1=>Channel 1
// <2=>Channel 2
// <3=>Channel 3
// <4=>Channel 4
// <5=>Channel 5
// <6=>Channel 6
// <7=>Channel 7
// <i>  Defines the bit user sequence.
// <id> adc_seqr1_usch1
#ifndef CONF_ADC_SEQR1_USCH1
#define CONF_ADC_SEQR1_USCH1 0
#endif

// <o> User Sequence Number 2
// <0=>Channel 0
// <1=>Channel 1
// <2=>Channel 2
// <3=>Channel 3
// <4=>Channel 4
// <5=>Channel 5
// <6=>Channel 6
// <7=>Channel 7
// <i>  Defines the bit user sequence.
// <id> adc_seqr1_usch2
#ifndef CONF_ADC_SEQR1_USCH2
#define CONF_ADC_SEQR1_USCH2 1
#endif

// <o> User Sequence Number 3
// <0=>Channel 0
// <1=>Channel 1
// <2=>Channel 2
// <3=>Channel 3
// <4=>Channel 4
// <5=>Channel 5
// <6=>Channel 6
// <7=>Channel 7
// <i>  Defines the bit user sequence.
// <id> adc_seqr1_usch3
#ifndef CONF_ADC_SEQR1_USCH3
#define CONF_ADC_SEQR1_USCH3 2
#endif

// <o> User Sequence Number 4
// <0=>Channel 0
// <1=>Channel 1
// <2=>Channel 2
// <3=>Channel 3
// <4=>Channel 4
// <5=>Channel 5
// <6=>Channel 6
// <7=>Channel 7
// <i>  Defines the bit user sequence.
// <id> adc_seqr1_usch4
#ifndef CONF_ADC_SEQR1_USCH4
#define CONF_ADC_SEQR1_USCH4 3
#endif

// <o> User Sequence Number 5
// <0=>Channel 0
// <1=>Channel 1
// <2=>Channel 2
// <3=>Channel 3
// <4=>Channel 4
// <5=>Channel 5
// <6=>Channel 6
// <7=>Channel 7
// <i>  Defines the bit user sequence.
// <id> adc_seqr1_usch5
#ifndef CONF_ADC_SEQR1_USCH5
#define CONF_ADC_SEQR1_USCH5 4
#endif

// <o> User Sequence Number 6
// <0=>Channel 0
// <1=>Channel 1
// <2=>Channel 2
// <3=>Channel 3
// <4=>Channel 4
// <5=>Channel 5
// <6=>Channel 6
// <7=>Channel 7
// <i>  Defines the bit user sequence.
// <id> adc_seqr1_usch6
#ifndef CONF_ADC_SEQR1_USCH6
#define CONF_ADC_SEQR1_USCH6 5
#endif

// <o> User Sequence Number 7
// <0=>Channel 0
// <1=>Channel 1
// <2=>Channel 2
// <3=>Channel 3
// <4=>Channel 4
// <5=>Channel 5
// <6=>Channel 6
// <7=>Channel 7
// <i>  Defines the bit user sequence.
// <id> adc_seqr1_usch7
#ifndef CONF_ADC_SEQR1_USCH7
#define CONF_ADC_SEQR1_USCH7 6
#endif

// </e>

// <e> Channel 0 Enable
// <i> Enables the corresponding channel
// <id> adc_cher_ch0
#ifndef CONF_ADC_CHER_CH0
#define CONF_ADC_CHER_CH0 1
#endif

// <q> Offset
// <i> Centers the analog signal on VADVREF/2
// <id> adc_cor_off0
#ifndef CONF_ADC_COR_OFF0
#define CONF_ADC_COR_OFF0 0
#endif

// <o> Differential Inputs Mode
// <0=>Single-ended mode
// <1=>Fully differential mode
// <id> adc_cor_diff0
#ifndef CONF_ADC_COR_DIFF0
#define CONF_ADC_COR_DIFF0 0
#endif

// </e>

// <e> Channel 1 Enable
// <i> Enables the corresponding channel
// <id> adc_cher_ch1
#ifndef CONF_ADC_CHER_CH1
#define CONF_ADC_CHER_CH1 0
#endif

// <q> Offset
// <i> Centers the analog signal on VADVREF/2
// <id> adc_cor_off1
#ifndef CONF_ADC_COR_OFF1
#define CONF_ADC_COR_OFF1 0
#endif

// <o> Differential Inputs Mode
// <0=>Single-ended mode
// <1=>Fully differential mode
// <id> adc_cor_diff1
#ifndef CONF_ADC_COR_DIFF1
#define CONF_ADC_COR_DIFF1 0
#endif

// </e>

// <e> Channel 2 Enable
// <i> Enables the corresponding channel
// <id> adc_cher_ch2
#ifndef CONF_ADC_CHER_CH2
#define CONF_ADC_CHER_CH2 0
#endif

// <q> Offset
// <i> Centers the analog signal on VADVREF/2
// <id> adc_cor_off2
#ifndef CONF_ADC_COR_OFF2
#define CONF_ADC_COR_OFF2 0
#endif

// <o> Differential Inputs Mode
// <0=>Single-ended mode
// <1=>Fully differential mode
// <id> adc_cor_diff2
#ifndef CONF_ADC_COR_DIFF2
#define CONF_ADC_COR_DIFF2 0
#endif

// </e>

// <e> Channel 3 Enable
// <i> Enables the corresponding channel
// <id> adc_cher_ch3
#ifndef CONF_ADC_CHER_CH3
#define CONF_ADC_CHER_CH3 0
#endif

// <q> Offset
// <i> Centers the analog signal on VADVREF/2
// <id> adc_cor_off3
#ifndef CONF_ADC_COR_OFF3
#define CONF_ADC_COR_OFF3 0
#endif

// <o> Differential Inputs Mode
// <0=>Single-ended mode
// <1=>Fully differential mode
// <id> adc_cor_diff3
#ifndef CONF_ADC_COR_DIFF3
#define CONF_ADC_COR_DIFF3 0
#endif

// </e>

// <e> Channel 4 Enable
// <i> Enables the corresponding channel
// <id> adc_cher_ch4
#ifndef CONF_ADC_CHER_CH4
#define CONF_ADC_CHER_CH4 0
#endif

// <q> Offset
// <i> Centers the analog signal on VADVREF/2
// <id> adc_cor_off4
#ifndef CONF_ADC_COR_OFF4
#define CONF_ADC_COR_OFF4 0
#endif

// <o> Differential Inputs Mode
// <0=>Single-ended mode
// <1=>Fully differential mode
// <id> adc_cor_diff4
#ifndef CONF_ADC_COR_DIFF4
#define CONF_ADC_COR_DIFF4 0
#endif

// </e>

// <e> Channel 5 Enable
// <i> Enables the corresponding channel
// <id> adc_cher_ch5
#ifndef CONF_ADC_CHER_CH5
#define CONF_ADC_CHER_CH5 0
#endif

// <q> Offset
// <i> Centers the analog signal on VADVREF/2
// <id> adc_cor_off5
#ifndef CONF_ADC_COR_OFF5
#define CONF_ADC_COR_OFF5 0
#endif

// <o> Differential Inputs Mode
// <0=>Single-ended mode
// <1=>Fully differential mode
// <id> adc_cor_diff5
#ifndef CONF_ADC_COR_DIFF5
#define CONF_ADC_COR_DIFF5 0
#endif

// </e>

// <e> Channel 6 Enable
// <i> Enables the corresponding channel
// <id> adc_cher_ch6
#ifndef CONF_ADC_CHER_CH6
#define CONF_ADC_CHER_CH6 0
#endif

// <q> Offset
// <i> Centers the analog signal on VADVREF/2
// <id> adc_cor_off6
#ifndef CONF_ADC_COR_OFF6
#define CONF_ADC_COR_OFF6 0
#endif

// <o> Differential Inputs Mode
// <0=>Single-ended mode
// <1=>Fully differential mode
// <id> adc_cor_diff6
#ifndef CONF_ADC_COR_DIFF6
#define CONF_ADC_COR_DIFF6 0
#endif

// </e>

// <e> Channel 7 Enable
// <i> Enables the corresponding channel
// <id> adc_cher_ch7
#ifndef CONF_ADC_CHER_CH7
#define CONF_ADC_CHER_CH7 0
#endif

// <q> Offset
// <i> Centers the analog signal on VADVREF/2
// <id> adc_cor_off7
#ifndef CONF_ADC_COR_OFF7
#define CONF_ADC_COR_OFF7 0
#endif

// <o> Differential Inputs Mode
// <0=>Single-ended mode
// <1=>Fully differential mode
// <id> adc_cor_diff7
#ifndef CONF_ADC_COR_DIFF7
#define CONF_ADC_COR_DIFF7 0
#endif

// </e>

// </h>

#if ((0 || CONF_ADC_CHANNEL0_ENABLE || CONF_ADC_CHANNEL1_ENABLE || CONF_ADC_CHANNEL2_ENABLE                            \
      || CONF_ADC_CHANNEL3_ENABLE                                                                                      \
      || CONF_ADC_CHANNEL4_ENABLE                                                                                      \
      || CONF_ADC_CHANNEL5_ENABLE                                                                                      \
      || CONF_ADC_CHANNEL6_ENABLE                                                                                      \
      || CONF_ADC_CHANNEL7_ENABLE)                                                                                     \
     == 0)
#warning Select one channel at least, check your configuration!
#endif

#define CONF_ADC_MR_REG                                                                                                \
	((CONF_ADC_MR_TRGEN << ADC_MR_TRGEN_Pos) | ADC_MR_TRGSEL(CONF_ADC_MR_TRGSEL)                                       \
	 | (CONF_ADC_MR_SLEEP << ADC_MR_SLEEP_Pos)                                                                         \
	 | (CONF_ADC_MR_FWUP << ADC_MR_FWUP_Pos)                                                                           \
	 | (CONF_ADC_MR_FREERUN << ADC_MR_FREERUN_Pos)                                                                     \
	 | ADC_MR_STARTUP(CONF_ADC_MR_STARTUP)                                                                             \
	 | ADC_MR_TRANSFER(CONF_ADC_MR_TRANSFER)                                                                           \
	 | ADC_MR_PRESCAL(CONF_ADC_MR_PRESCAL)                                                                             \
	 | (CONF_ADC_MR_USEQ << ADC_MR_USEQ_Pos))

#define CONF_ADC_EMR_REG                                                                                               \
	(ADC_EMR_OSR(CONF_ADC_EMR_OSR) | ADC_EMR_CMPMODE(CONF_ADC_EMR_CMPMODE)                                             \
	 | CONF_ADC_EMR_CMPTYPE << ADC_EMR_CMPTYPE_Pos                                                                     \
	 | ADC_EMR_CMPSEL(CONF_ADC_EMR_CMPSEL)                                                                             \
	 | CONF_ADC_EMR_CMPALL << ADC_EMR_CMPALL_Pos                                                                       \
	 | ADC_EMR_CMPFILTER(CONF_ADC_EMR_CMPFILTER)                                                                       \
	 | CONF_ADC_EMR_ASTE << ADC_EMR_ASTE_Pos                                                                           \
	 | CONF_ADC_EMR_SRCCLK << ADC_EMR_SRCCLK_Pos                                                                       \
	 | CONF_ADC_EMR_TAG << ADC_EMR_TAG_Pos)
#define CONF_ADC_LCCWR_REG (ADC_LCCWR_LOWTHRES(CONF_ADC_LOWTHRES) | ADC_LCCWR_HIGHTHRES(CONF_ADC_HIGHTHRES))

#define CONF_ADC_ACR_REG (ADC_ACR_AUTOTEST(CONF_ADC_ACR_AUTOTEST))

#define CONF_ADC_SEQR1_REG                                                                                             \
	(ADC_SEQR1_USCH1(CONF_ADC_SEQR1_USCH1) | ADC_SEQR1_USCH2(CONF_ADC_SEQR1_USCH2)                                     \
	 | ADC_SEQR1_USCH3(CONF_ADC_SEQR1_USCH3)                                                                           \
	 | ADC_SEQR1_USCH4(CONF_ADC_SEQR1_USCH4)                                                                           \
	 | ADC_SEQR1_USCH5(CONF_ADC_SEQR1_USCH5)                                                                           \
	 | ADC_SEQR1_USCH6(CONF_ADC_SEQR1_USCH6)                                                                           \
	 | ADC_SEQR1_USCH7(CONF_ADC_SEQR1_USCH7))

#define CONF_ADC_CHER_REG                                                                                              \
	((CONF_ADC_CHER_CH0 << ADC_CHER_CH0_Pos) | (CONF_ADC_CHER_CH1 << ADC_CHER_CH1_Pos)                                 \
	 | (CONF_ADC_CHER_CH2 << ADC_CHER_CH2_Pos)                                                                         \
	 | (CONF_ADC_CHER_CH3 << ADC_CHER_CH3_Pos)                                                                         \
	 | (CONF_ADC_CHER_CH4 << ADC_CHER_CH4_Pos)                                                                         \
	 | (CONF_ADC_CHER_CH5 << ADC_CHER_CH5_Pos)                                                                         \
	 | (CONF_ADC_CHER_CH6 << ADC_CHER_CH6_Pos)                                                                         \
	 | (CONF_ADC_CHER_CH7 << ADC_CHER_CH7_Pos))
#define CONF_ADC_COR_REG                                                                                               \
	((CONF_ADC_COR_OFF0 << ADC_COR_OFF0_Pos) | (CONF_ADC_COR_OFF1 << ADC_COR_OFF1_Pos)                                 \
	 | (CONF_ADC_COR_OFF2 << ADC_COR_OFF2_Pos)                                                                         \
	 | (CONF_ADC_COR_OFF3 << ADC_COR_OFF3_Pos)                                                                         \
	 | (CONF_ADC_COR_OFF4 << ADC_COR_OFF4_Pos)                                                                         \
	 | (CONF_ADC_COR_OFF5 << ADC_COR_OFF5_Pos)                                                                         \
	 | (CONF_ADC_COR_OFF6 << ADC_COR_OFF6_Pos)                                                                         \
	 | (CONF_ADC_COR_OFF7 << ADC_COR_OFF7_Pos)                                                                         \
	 | (CONF_ADC_COR_DIFF0 << ADC_COR_DIFF0_Pos)                                                                       \
	 | (CONF_ADC_COR_DIFF1 << ADC_COR_DIFF1_Pos)                                                                       \
	 | (CONF_ADC_COR_DIFF2 << ADC_COR_DIFF2_Pos)                                                                       \
	 | (CONF_ADC_COR_DIFF3 << ADC_COR_DIFF3_Pos)                                                                       \
	 | (CONF_ADC_COR_DIFF4 << ADC_COR_DIFF4_Pos)                                                                       \
	 | (CONF_ADC_COR_DIFF5 << ADC_COR_DIFF5_Pos)                                                                       \
	 | (CONF_ADC_COR_DIFF6 << ADC_COR_DIFF6_Pos)                                                                       \
	 | (CONF_ADC_COR_DIFF7 << ADC_COR_DIFF7_Pos))

// <<< end of configuration section >>>

#endif // HPL_ADC_CONFIG_H
