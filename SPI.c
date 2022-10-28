#include <pic18f45k22.h>

#include "SPI.h"
#include "picuno.h"

void SPI_begin(void){
    //SPI setup
    SPI_setting(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
}

unsigned char SPI_transfer(unsigned char txd)
{
    uint8_t rxd=0;
		SSP1CON1bits.WCOL = 0;
		if(SSP1STATbits.BF) rxd = SSP1BUF;
		SSP1BUF = txd;
		while(!SSP1STATbits.BF);
		rxd = SSP1BUF;
		return rxd;
}

void SPI_setting(Spi_Type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge)
{
    TRISCbits.TRISC5 = 0;       //SDO
    if(sType & 0b00000100)      //If Slave Mode
    {
        SSP1STAT = sTransmitEdge;
        TRISCbits.TRISC3 = 1;  //Salve:SCK as INPUT
    }
    else                        //If Master Mode
    {
        SSP1STAT = sDataSample | sTransmitEdge;
        TRISCbits.TRISC3 = 0;   //Master:SCK as OUTPUT
    }
    SSP1ADD = 0x01;
    SSP1CON1 = sType | sClockIdle;
}

void SPI_end(void)
{
    SSP1CON1bits.SSPEN = 0;
}

//Slave section
static void SPI_receiveWait()
{
    while ( !SSP1STATbits.BF ); // Wait for Data Transmit/Receipt complete
}

void SPI_write(char dat)  //Write data to SPI bus
{
    SSP1BUF = dat;
}

unsigned char SPI_dataReady() //Check whether the data is ready to read
{
    if(SSP1STATbits.BF)
        return 1;
    else
        return 0;
}

unsigned char SPI_read() //REad the received data
{
    SPI_receiveWait();        // wait until the all bits receive
    return(SSP1BUF); // read the received data from the buffer
}
