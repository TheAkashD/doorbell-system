//sleep test
#include <avr/sleep.h>
#define button 2

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  //digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinking();
  delay(500);
  sendToSleep();
  
}

void sendToSleep()
{
  Serial.println("System deactivating...");
  sleep_enable();
  attachInterrupt(0,wakeUp,LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  //digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  sleep_cpu();
  Serial.println("System activated!");
  //digitalWrite(LED_BUILTIN, LOW);
}

void wakeUp()
{
  Serial.println("Interrupt fired");
  sleep_disable();
  detachInterrupt(0);
}

void blinking()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
}
