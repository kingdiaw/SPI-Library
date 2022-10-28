#include "picuno.h"
#include "SPI.h"

#define SS_dir  TRISDbits.TRISD1
#define SS      LATDbits.LATD1

void setup(){
  Serial_begin(9600);
  SPI_begin();
  SS_dir = 0;
  SS = 0;
}
char buf[32];
int number;
unsigned char rtnVal;
void loop(){
    if(timerUp(0)){
        timerSet(0,1000);
        SS = 0;
        delay(10);
        SPI_write(number);
        rtnVal = SPI_read();
        SS = 1;
        sprintf(buf,"rtnVal=%d    sendVal=%d",rtnVal,number);
        Serial_println(buf);
        number++;
    }
}
