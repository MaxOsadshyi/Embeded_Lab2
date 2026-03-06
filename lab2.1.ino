#include <Arduino.h>

#define ADC_PIN 34
#define LED_PIN 25

int read()
{
  return analogRead(ADC_PIN);
}

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int value = read();
  Serial.println(value);
  delay(1500);
  if (value >= 1500)
  {
    dacWrite(LED_PIN, 0);
  }
  else
  {
    dacWrite(LED_PIN, 255);
  }
  delay(500);
}