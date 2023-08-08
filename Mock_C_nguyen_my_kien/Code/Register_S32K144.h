/*
** ###################################################################
**     Processor:           S32K144
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 11/07/2023
**
**     Abstract:
**         Peripheral Access Layer for S32K144
**
** ###################################################################
*/

/* Prevention from multiple including the same memory map */
#if !defined(Register_S32K144_H_)  /* Check if memory map has not been already included */
#define (Register_S32K144_H_)  

/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* SCG */
typedef struct {
  volatile const unsigned int SCG_VERID;
  volatile const unsigned int SCG_PARAM;
  char dummy1[8];
  volatile const unsigned int SCG_CSR;
  volatile unsigned int SCG_RCCR;
  volatile unsigned int SCG_VCCR;
  volatile unsigned int SCG_HCCR;
  volatile unsigned int SCG_CLKOUTCNFG;
  char dummy2[220];
  volatile unsigned int SCG_SOSCCSR;
  volatile unsigned int SCG_SOSCDIV;
  volatile unsigned int SCG_SOSCCFG;
  char dummy3[244];
  volatile unsigned int SCG_SIRCCSR;
  volatile unsigned int SCG_SIRCDIV;
  volatile unsigned int SCG_SIRCCFG;
  char dummy4[244];
  volatile unsigned int SCG_FIRCCSR;
  volatile unsigned int SCG_FIRCDIV;
  volatile unsigned int SCG_FIRCCFG;
  char dummy5[756];
  volatile unsigned int SCG_SPLLCSR;
  volatile unsigned int SCG_SPLLDIV;
  volatile unsigned int SCG_SPLLCFG;
} SCG_REG;

#define SCG_BASE_ADDRS (0x40064000)
#define SCG ((SCG_REG*)SCG_BASE_ADDRS)

/* PCC */
typedef struct {
  volatile unsigned int PCC_DMAMUX;
  char PCC_dummy1[8];
  volatile unsigned int PCC_FlexCAN0;
  volatile unsigned int PCC_FlexCAN1;
  volatile unsigned int PCC_FTM3;
  volatile unsigned int PCC_ADC1;
  char PCC_dummy2[12];
  volatile unsigned int PCC_FlexCAN2;
  volatile unsigned int PCC_LPSPI0;
  volatile unsigned int PCC_LPSPI1;
  volatile unsigned int PCC_LPSPI2;
  char PCC_dummy3[8];
  volatile unsigned int PCC_PDB1;
  volatile unsigned int PCC_CRC;
  char PCC_dummy4[12];
  volatile unsigned int PCC_PDB0;
  volatile unsigned int PCC_LPIT;
  volatile unsigned int PCC_FTM0;
  volatile unsigned int PCC_FTM1;
  volatile unsigned int PCC_FTM2;
  volatile unsigned int PCC_ADC0;
  char PCC_dummy5[4];
  volatile unsigned int PCC_RTC;
  char PCC_dummy6[8];
  volatile unsigned int PCC_LPTMR0;
  char PCC_dummy7[32];
  volatile unsigned int PCC_PORTA;
  volatile unsigned int PCC_PORTB;
  volatile unsigned int PCC_PORTC;
  volatile unsigned int PCC_PORTD;
  volatile unsigned int PCC_PORTE;
  char PCC_dummy8[24];
  volatile unsigned int PCC_SAI0;
  volatile unsigned int PCC_SAI1;
  char PCC_dummy9[16];
  volatile unsigned int PCC_FlexIO;
  char PCC_dummy10[24];
  volatile unsigned int PCC_EWM;
  char PCC_dummy11[16];
  volatile unsigned int PCC_LPI2C0;
  volatile unsigned int PCC_LPI2C1;
  char PCC_dummy12[8];
  volatile unsigned int PCC_LPUART0;
  volatile unsigned int PCC_LPUART1;
  volatile unsigned int PCC_LPUART2;
  char PCC_dummy13[4];
  volatile unsigned int PCC_FTM4;
  volatile unsigned int PCC_FTM5;
  volatile unsigned int PCC_FTM6;
  volatile unsigned int PCC_FTM7;
  char PCC_dummy14[4];
  volatile unsigned int PCC_CMP0;
  char PCC_dummy15[8];
  volatile unsigned int PCC_QSPI;
  char PCC_dummy16[8];
  volatile unsigned int PCC_ENET;
} PCC_REG;

#define PCC_BASE_ADDRS (0x40065000)
#define PCC ((PCC_REG*)PCC_BASE_ADDRS)

#endif  /* #if !defined(Register_S32K144_H_) */
