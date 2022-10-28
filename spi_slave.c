#include "picuno.h"
#include "SPI.h"

#define SS_dir  TRISAbits.TRISA5    //SS at RA5

void setup(){
  Serial_begin(9600);
  SPI_setting(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
  SS_dir = 1;
}
char buf[32];
unsigned char rxd;
unsigned char txd;

void loop(){
    if(SPI_dataReady()){
        rxd = SPI_read();
        txd = rxd+1;        
        SPI_write(txd);
        sprintf(buf,"Received:%d    Transmitted:%d",rxd,txd);
        Serial_println(buf);
    }
}
