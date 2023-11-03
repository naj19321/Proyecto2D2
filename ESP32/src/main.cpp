#include <Arduino.h>

const int lm35Pin = 35; // Pin al que está conectado el sensor LM35
const int uartTX = 17; // Pin TX UART2 (GPIO17)
const int uartRX = 16; // Pin RX UART2 (GPIO16)

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, uartRX, uartTX);
}

void loop() {
  // Leer el valor analógico del sensor LM35
  int sensorValue = analogRead(lm35Pin);

  // Convertir el valor analógico a temperatura en grados Celsius
  float temperatureC = (sensorValue / 4095.0) * 3300.0 / 10.0;

  // Enviar la temperatura por UART2
  Serial2.print("Temperatura (C): ");
  Serial2.println(temperatureC);

  delay(1000); // Esperar 1 segundo antes de enviar otra lectura
}
