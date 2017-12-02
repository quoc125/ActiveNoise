/* Auto-generated config file peripheral_clk_config.h */
#ifndef PERIPHERAL_CLK_CONFIG_H
#define PERIPHERAL_CLK_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <h> AFEC Clock Settings
// <o> AFEC Clock source
// <0=> Master Clock (MCK)
// <i> This defines the clock source for the ADC
// <id> adc_clock_source
#ifndef CONF_ADC_SRC
#define CONF_ADC_SRC 0
#endif
// </h>

/**
 * \def ADC FREQUENCY
 * \brief ADC's Clock frequency
 */
#ifndef CONF_ADC_FREQUENCY
#define CONF_ADC_FREQUENCY 8000000
#endif

/**
 * \def CONF_HCLK_FREQUENCY
 * \brief HCLK's Clock frequency
 */
#ifndef CONF_HCLK_FREQUENCY
#define CONF_HCLK_FREQUENCY 8000000
#endif

/**
 * \def CONF_FCLK_FREQUENCY
 * \brief FCLK's Clock frequency
 */
#ifndef CONF_FCLK_FREQUENCY
#define CONF_FCLK_FREQUENCY 8000000
#endif

/**
 * \def CONF_CPU_FREQUENCY
 * \brief CPU's Clock frequency
 */
#ifndef CONF_CPU_FREQUENCY
#define CONF_CPU_FREQUENCY 8000000
#endif

/**
 * \def CONF_SLCK_FREQUENCY
 * \brief Slow Clock frequency
 */
#define CONF_SLCK_FREQUENCY 0

/**
 * \def CONF_MCK_FREQUENCY
 * \brief Master Clock frequency
 */
#define CONF_MCK_FREQUENCY 8000000

// <h> FLEXCOM Clock Settings
// <o> FLEXCOM Clock source
// <0=> Master Clock (MCK)
// <1=> MCK / 8
// <2=> Programmable Clock Controller 6 (PMC_PCK6)
// <2=> Programmable Clock Controller 7 (PMC_PCK7)
// <3=> External Clock
// <i> This defines the clock source for the FLEXCOM, PCK6 is used for FLEXCOM0/1/2/3 and PCK7 is used for FLEXCOM4/5/6/7
// <id> flexcom_clock_source
#ifndef CONF_FLEXCOM3_CK_SRC
#define CONF_FLEXCOM3_CK_SRC 0
#endif

// <o> FLEXCOM External Clock Input on SCK <1-4294967295>
// <i> Inputs the external clock frequency on SCK
// <id> flexcom_clock_freq
#ifndef CONF_FLEXCOM3_SCK_FREQ
#define CONF_FLEXCOM3_SCK_FREQ 10000000
#endif

// </h>

/**
 * \def FLEXCOM FREQUENCY
 * \brief FLEXCOM's Clock frequency
 */
#ifndef CONF_FLEXCOM3_FREQUENCY
#define CONF_FLEXCOM3_FREQUENCY 8000000
#endif

// <<< end of configuration section >>>

#endif // PERIPHERAL_CLK_CONFIG_H
