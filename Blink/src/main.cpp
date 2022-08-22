// Blinking led on Arduino for PlatformIo=O
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

#include "Arduino.h"              // Підключаємо ядро Arduino

void setup() {                    // Ініціалізація програми
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);   // Встановити пін як вихід
}

void loop() {                       // Безкінечний цикл
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);  // Подаємо 5V на пін 
  delay(500);                       // Чекаємо 500 мс = 0.5 с
  digitalWrite(LED_BUILTIN, LOW);   // Подаємо 0V на пін
  delay(500);                       // Чекаємо 500 мс = 0.5 с-
}