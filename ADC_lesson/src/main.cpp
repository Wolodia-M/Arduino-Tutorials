// Reading analog input on Arduino with PlatformIO
// Copyright (C) 2022 WolodiaM

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Arduino.h>

#define POT A5        // Пін, на який підключено потенціометр
#define LED A1        // Пін, на який підключено світлодіод
#define VALUE 400     // Значення для події
#define TRESHOLD 100  // Діапазон

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);     // Почати передачу по послідовному порту
  pinMode(POT, INPUT);    // Встановити пін як вхід
  pinMode(LED, OUTPUT);   // Встановити пін як вихід
}

// Зчитати знаяення з АЦП і вивести у термінал та включити світлодіод у певному діапазоні значень
void loop() {
  int value = 0;                // Створення змінної
  value = analogRead(POT);      // Зчитати аналогове значення з піна
  Serial.println(value);        // Вивести значення у послідовний порт
  if ((value > (VALUE - TRESHOLD)) && (value < (VALUE + TRESHOLD))) // Якщо значення Попадає у потрібний діапазон
  {
    digitalWrite(LED, HIGH);  // Включитьи світлодіод
  }
  else 
  {
    digitalWrite(LED, LOW);   // Інакше - виключити
  }
}

// Зчитати знаяення з АЦП і вивести у термінал
// void loop() {
//   // put your main code here, to run repeatedly:
//   int value = 0;            // Створення змінної
//   value = analogRead(POT);  // Зчитати аналогове значення з піна
//   Serial.println(value);    // Вивести значення у послідовний порт
// }
