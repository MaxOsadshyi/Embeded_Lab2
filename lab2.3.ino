#include <SPI.h>
#include <Adafruit_BMP280.h>

// Визначаємо пін CS (Chip Select)
#define BMP_CS 5

// Створюємо об'єкт для роботи через апаратний SPI
Adafruit_BMP280 bmp(BMP_CS);

void setup() {
  Serial.begin(115200);
  Serial.println("Тестування SPI з одним BMP280...");

  // Ініціалізація датчика
  if (!bmp.begin()) {
    Serial.println("Помилка! Датчик не знайдено.");
    Serial.println("Перевірте підключення: CS->5, SCK->18, MOSI->23, MISO->19");
    while (1);
  }
  Serial.println("Датчик знайдено успішно!");
}

void loop() {
  // Зчитування даних згідно з завданням 
  Serial.print("Температура: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Тиск: ");
  Serial.print(bmp.readPressure() / 100.0F); // Конвертація в гПа
  Serial.println(" hPa");

  Serial.println("-----------------------");
  delay(2000);
}