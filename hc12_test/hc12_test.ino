#include <SoftwareSerial.h>

#define tx 3
#define rx 2

SoftwareSerial hc12(tx, rx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hc12.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(hc12.available())
  {
    Serial.write(hc12.read());
  }
  if(Serial.available())
  {
    hc12.write(Serial.read());
  }
}
