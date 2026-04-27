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

#ifndef LED_BUILTIN
#pragma "LED_BUILTIN is not defined. Please define LED_BUILTIN in your board variant file or use an external LED connected to a GPIO pin and update the code accordingly."
#define LED_BUILTIN 14
#endif

int hallValue = 0;

void setup()
{
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // off, depend on LED circuit, can also be HIGH
}

void loop()
{
  hallValue = hallRead();

  Serial.print("Hall Sensor Value: ");
  Serial.println(hallValue);

  if (hallValue < 0) {
    Serial.println("Negative magnetic field detected. Switching LED on.");
    digitalWrite(LED_BUILTIN, LOW); // depend on LED circuit, can also be HIGH
  } else {
    Serial.println("Positive or earth neutral magnetic field detected. Switching LED off.");
    digitalWrite(LED_BUILTIN, HIGH);
  }

  delay(2);
}
