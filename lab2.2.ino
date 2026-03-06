#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(115200);

  if (!bmp.begin(0x76)) {
    Serial.println("BMP280 не знайдено!");
    while (1);
  }

  Serial.println("BMP280 знайдено!");
}

void loop() {
  Serial.print("Температура: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" C");

  Serial.print("Тиск: ");
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(" hPa");

  delay(2000);
}