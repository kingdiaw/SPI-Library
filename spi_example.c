#include "picuno.h"
#include "SPI.h"

void setup(){
  Serial_begin(9600);
  SPI_begin();
  TRISDbits.TRISD1 = 0;
}
char buf[32];
int number;
void loop(){
    if(timerUp(0)){
        timerSet(0,1000);
        LATDbits.LATD1 = 0;
        delay(10);
        uint8_t rtnVal = SPI_transfer(number++);
        LATDbits.LATD1 = 1;
        sprintf(buf,"rtnVal=%d\tsendVal=%d",rtnVal,number);
        Serial_println(buf);
    }
}
