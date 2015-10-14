#include <SPI.h>
#include <RF24.h>
#include "printf.h"
#include <Servo.h>
#define CE 9
#define CS 10
#define ROLE 7
#define BAUD 57600
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
  if ( radio.available() )
  {
    unsigned long got_time;
    bool done = false;
    while (!done)
    {
      done = radio.read( &got_time, sizeof(unsigned long) );
    }
    unsigned long id1=got_time/10000;
    unsigned long val=got_time-(id1*10000);
    unsigned long id=id1;
    if(id1==11) id=14;
    if(id1==12) id=11;
    if(id1==13) id=13;
    if(id1==14) id=12;
    if(id1==15) id=18;
    if(id1==16) id=17;
    if(id1==17) id=16;
    if(id1==18) id=15;
    if(id1==19) id=19;
    if(id==11) Serial.print("RWN");
    if(id==12) Serial.print("RWE");
    if(id==13) Serial.print("RWS");
    if(id==14) Serial.print("RWW");
    if(id==15) Serial.print("RLN");
    if(id==16) Serial.print("RLE");
    if(id==17) Serial.print("RLS");
    if(id==18) Serial.print("RLW");
    if(id==19) Serial.print("RTZ");
    if(id==21) Serial.print("I1L");
    if(id==22) Serial.print("I1T");
    if(id==30) Serial.print("ID0");
    if(id==31) Serial.print("ID1");
    if(id==32) Serial.print("ID2");
    if(id==33) Serial.print("ID3");
    if(id==34) Serial.print("ID4");
    if(id==35) Serial.print("ID5");
    if(id==36) Serial.print("ID6");
    if(id==37) Serial.print("ID7");
    if(id==38) Serial.print("ID8");
    if(id==39) Serial.print("ID9");
    
    Serial.print("00");
    Serial.print(id);
    
    Serial.print(val);
    Serial.println();
    //Serial.println(got_time);
    radio.stopListening();

    radio.startListening();
  }
}
// vim:cin:ai:sts=2 sw=2 ft=cpp
