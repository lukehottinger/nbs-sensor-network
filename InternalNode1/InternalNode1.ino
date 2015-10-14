
#include <SPI.h>
#include <RF24.h>
#include "printf.h"
#include <Servo.h>
#define CE 9
#define CS 10
#define ROLE 7
#define BAUD 57600

const int Light=A4;
const int Temp=A5;
int temp1=1;
int temp2=1;
int temp3=1;
int temp4=1;
int temp5=1;
int temp6=1;
int temp7=1;
int temp8=1;
int temp9=1;
int temp0=1;

RF24 radio(CE, CS);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

void setup(void)
{
  Serial.begin(BAUD);
  printf_begin();
  radio.begin();
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);
  radio.enableDynamicPayloads() ;
  radio.setAutoAck( true ) ;
  radio.powerUp() ;
  radio.startListening();
  radio.printDetails();
}
void loop(void)
{
   radio.stopListening();
   
   int L=analogRead(Light);
   int T=analogRead(Temp);
   int temp=0;
   
   
  
   unsigned long integerValue=210000+L;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=220000+T;
   radio.write( &integerValue, sizeof(unsigned long) );
   for(int i=0;i<100;i++)
   {
     delay(100);
     if(digitalRead(8)!=temp1)
     {
       temp1=digitalRead(8);
       integerValue=300000+temp1;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(7)!=temp2)
     {
       temp2=digitalRead(7);
       integerValue=310000+temp2;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(6)!=temp3)
     {
       temp3=digitalRead(6);
       integerValue=320000+temp3;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(5)!=temp4)
     {
       temp4=digitalRead(5);
       integerValue=330000+temp4;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(4)!=temp5)
     {
       temp5=digitalRead(4);
       integerValue=340000+temp5;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(3)!=temp6)
     {
       temp6=digitalRead(3);
       integerValue=350000+temp6;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(A0)!=temp7)
     {
       temp7=digitalRead(A0);
       integerValue=360000+temp7;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(A1)!=temp8)
     {
       temp8=digitalRead(A1);
       integerValue=370000+temp8;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(A2)!=temp9)
     {
       temp9=digitalRead(A2);
       integerValue=380000+temp9;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
     if(digitalRead(A3)!=temp0)
     {
       temp0=digitalRead(A3);
       integerValue=390000+temp0;
       radio.write( &integerValue, sizeof(unsigned long) );
     }
   }
   
   
}
// vim:cin:ai:sts=2 sw=2 ft=cpp
