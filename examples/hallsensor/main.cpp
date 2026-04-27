/**
 * This example shows how to use a built-in LED with low energy consumption
 *
 * used features:
 * - blink built-in LED
 * - Deep-Sleep mode
 *
 * see https://docs.arduino.cc/built-in-examples/basics/Blink
 */
#include <Arduino.h>

#define uS_TO_MS_FACTOR 1000

#ifndef LED_BUILTIN
#pragma "LED_BUILTIN is not defined. Please define LED_BUILTIN in your board variant file or use an external LED connected to a GPIO pin and update the code accordingly."
#define LED_BUILTIN 14
#endif

int hallValue = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  // Serial.println("switch LED on");
  // digitalWrite(LED_BUILTIN, LOW); // depend on LED circuit, can also be HIGH
  // delay(200);

  // Serial.println("switch LED off");
  // digitalWrite(LED_BUILTIN, HIGH);
  // esp_sleep_enable_timer_wakeup(1000 * uS_TO_MS_FACTOR); // 1s
  // esp_deep_sleep_start();
}

void loop()
{
  hallValue = hallRead();
  Serial.print("Hall Sensor Value: ");
  Serial.println(hallValue);

  if (hallValue < -100) {
    Serial.println("Magnetic field detected! Switching LED on.");
    digitalWrite(LED_BUILTIN, LOW); // depend on LED circuit, can also be HIGH
  } else {
    Serial.println("No magnetic field detected. Switching LED off.");
    digitalWrite(LED_BUILTIN, HIGH);
  }

  delay(200);
}
