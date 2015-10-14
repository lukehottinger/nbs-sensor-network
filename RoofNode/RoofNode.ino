
#include <SPI.h>
#include <RF24.h>
#include "printf.h"
#include <Servo.h>
#define CE 9
#define CS 10
#define ROLE 7
#define BAUD 57600

const int WindNorth = A0;
const int WindEast  = A1;
const int WindSouth = A2;
const int WindWest  = A3;

const int LightNorth = A4;
const int LightEast  = A5;
const int LightSouth = A6;
const int LightWest  = A7;

const int TempNorth = A8;
const int TempEast  = A9;
const int TempSouth = A10;
const int TempWest  = A11;

RF24 radio(CE, CS);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
Servo myServo1;
Servo myServo2;
unsigned int leftLight=0;
unsigned int rightLight=0;
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
   delay(1000*15);
   int WN=analogRead(WindNorth);
   int WE=analogRead(WindEast);
   int WS=analogRead(WindSouth);
   int WW=analogRead(WindWest);
   
   int LN=analogRead(LightNorth);
   int LE=analogRead(LightEast);
   int LS=analogRead(LightSouth);
   int LW=analogRead(LightWest);
   
   int TN=analogRead(TempNorth);
   int TE=analogRead(TempEast);
   int TS=analogRead(TempSouth);
   int TW=analogRead(TempWest);
   
   int Temp=(TN+TE+TS+TW)/4;
   unsigned long integerValue=110000+WN;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=120000+WE;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=130000+WS;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=140000+WW;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=150000+LN;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=160000+LE;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=170000+LS;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=180000+LW;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   integerValue=190000+Temp;
   radio.write( &integerValue, sizeof(unsigned long) );
   
   
}
// vim:cin:ai:sts=2 sw=2 ft=cpp
