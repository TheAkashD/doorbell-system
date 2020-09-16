#include <SoftwareSerial.h>

#define tx 3
#define rx 2
#define button 8

int oldValue;
int newValue;

SoftwareSerial hc12(tx, rx);

void setup() {
  Serial.begin(9600);
  hc12.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  newValue=digitalRead(button);
  
  if(hc12.available())
  {
    Serial.write(hc12.read());
  }
  if(Serial.available())
  {
    hc12.write(Serial.read());
  }
  
  if(oldValue != newValue)
  {
    hc12.write(newValue);
    Serial.println(newValue);
    oldValue = newValue;
  }
  
}
