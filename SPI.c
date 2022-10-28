#include <pic18f45k22.h>

#include "SPI.h"
#include "picuno.h"

void SPI_begin(void){
    //SPI setup
    SPI_setting(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
//    SSP1STAT = 0x40;
//    SSP1CON1 = 0x00;		//0 = Idle state for clock is a low level
//    SSP1ADD = 0x01;		
//    TRISCbits.TRISC3 = 0;	//Synchronous serial clock input (SLAVE)/output (MASTER) for SPI mode
//    SSP1CON1bits.SSPEN = 1;	//Enables serial port and configures SCKx, SDOx, SDIx and SSx as the source of the serial port pins(2)
//    TRISCbits.TRISC5 = 0;   //SDO as OUTPUT
//    TRISCbits.TRISC4 = 1;   //SDI as INPUT
}

unsigned char SPI_transfer(unsigned char txd)
{
    uint8_t rxd=0;
		SSPCON1bits.WCOL = 0;
		if(SSPSTATbits.BF) rxd = SSPBUF;
		SSPBUF = txd;
		while(!SSPSTATbits.BF);
		rxd = SSPBUF;
		return rxd;
}

void SPI_setting(Spi_Type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge)
{
    TRISCbits.TRISC5 = 0;       //SDO
    if(sType & 0b00000100) //If Slave Mode
    {
        SSP1STAT = sTransmitEdge;
        TRISCbits.TRISC3 = 1;  //Salve:SCK as INPUT
    }
    else              //If Master Mode
    {
        SSP1STAT = sDataSample | sTransmitEdge;
        TRISCbits.TRISC3 = 0;   //Master:SCK as OUTPUT
    }
    SSP1ADD = 0x01;
    SSP1CON1 = sType | sClockIdle;
}

//void spiInit(Spi_Type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge)
//{
//    TRISCbits.TRISC5 = 0;
//    if(sType & 0b00000100) //If Slave Mode
//    {
//        SSP1STAT = sTransmitEdge;
//        TRISCbits.TRISC3 = 1;
//    }
//    else              //If Master Mode
//    {
//        SSP1STAT = sDataSample | sTransmitEdge;
//        TRISCbits.TRISC3 = 0;
//    }
//    SSP1ADD = 0x01;
//    SSP1CON1 = sType | sClockIdle;
//}

void SPI_end(void)
{
    SSP1CON1bits.SSPEN = 0;
}