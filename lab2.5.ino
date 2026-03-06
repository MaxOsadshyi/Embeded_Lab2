#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
#define ADC_PIN 34

// BMP280
Adafruit_BMP280 bmp;

// DS18B20
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Фоторезистор
int readPhotoresistor()
{
  return analogRead(ADC_PIN);
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Система датчиків запущена");

  // Ініціалізація DS18B20
  sensors.begin();

  // Ініціалізація BMP280
  if (!bmp.begin(0x76))
  {
    Serial.println("BMP280 не знайдено!");
    while (1);
  }

  Serial.println("BMP280 знайдено!");
}

void loop()
{
  // ---- DS18B20 ----
  sensors.requestTemperatures();
  float tempDS = sensors.getTempCByIndex(0);

  if (tempDS != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Температура DS18B20: ");
    Serial.print(tempDS);
    Serial.println(" C");
  }
  else
  {
    Serial.println("Помилка: DS18B20 не знайдено!");
  }

  // ---- BMP280 ----
  Serial.print("Температура BMP280: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" C");

  Serial.print("Тиск: ");
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(" hPa");

  // ---- Фоторезистор ----
  int lightValue = readPhotoresistor();
  Serial.print("Освітленість: ");
  Serial.println(lightValue);

  Serial.println("-----------------------");

  delay(2000);
}