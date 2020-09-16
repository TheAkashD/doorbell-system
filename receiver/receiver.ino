#include <SoftwareSerial.h>

#define tx 3
#define rx 2 
int isPushed = 1;

SoftwareSerial hc12(tx, rx);

void setup() {
  Serial.begin(9600);
  hc12.begin(9600);
}

void loop() 
{
  if(hc12.available())
  {
    Serial.write(hc12.read());
    //isPushed=hc12.read();
  }
  if(Serial.available())
  {
    hc12.write(Serial.read());
  }
  Serial.println(isPushed);

  isPushed=hc12.read();
  if(isPushed == 0)
  {
    ring();
  }
}
void ring()
{
  tone(9, 392);
  delay(400);
  noTone(9);
  tone(9, 262);
  delay(400);
  noTone(9);
  delay(500);
}
