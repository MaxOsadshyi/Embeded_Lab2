#include <OneWire.h>
#include <DallasTemperature.h>

// Пін, до якого підключений DS18B20 (наприклад, GPIO 4)
#define ONE_WIRE_BUS 4

// Налаштування OneWire
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  Serial.println("DS18B20: Тест одного датчика");

  sensors.begin(); // Ініціалізація
}

void loop() {
  // Запит на вимірювання температури
  sensors.requestTemperatures(); 

  // Зчитуємо дані лише для першого датчика (індекс 0)
  float tempC = sensors.getTempCByIndex(0);

  // Перевірка, чи датчик підключений
  if (tempC != DEVICE_DISCONNECTED_C) {
    Serial.print("Температура: ");
    Serial.print(tempC);
    Serial.println(" *C");
  } else {
    Serial.println("Помилка: Датчик не знайдено!");
  }

  Serial.println("-----------------------");
  delay(2000); // Оновлення кожні 2 секунди
}