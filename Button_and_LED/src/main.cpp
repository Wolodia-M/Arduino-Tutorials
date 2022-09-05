// Reading digital input on Arduino with PlatformIO
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
#include "btnapi.h"

// Піни до яких підключено щось
#define LED 8
#define BUTTON 2

btnapi btn(BUTTON, HIGH_PULL, NORM_CLOSE);

void setup() {
  // put your setup code here, to run once:
  // Встановлення посатковві настройки для пінів
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

// Потрібно розкоментувати хочаьи один і тільки один варіант!

// Програма з бібліотекою
// void loop() {
//   // put your main code here, to run repeatedly:
//   static bool ledState = 0;         // Стан світлодіода
//   btn.tick();
//   if(btn.isClick())                 // Якщо кнопка клікнута - змінити стан світлодіода
//   {
//     ledState = !ledState;
//   }
//   digitalWrite(LED, ledState);      // Міняємо стан світлодіода
// }

// Складніша програма
// void loop() {
//   // put your main code here, to run repeatedly:
//   static bool pinState = 0;         // Зміння, в яку буде записано значення з кнопки
//   static bool previviousState = 0;  // Попереднє значення кнопки
//   static bool ledState = 0;         // Стан світлодіода
//   static int deb = 0;               // Чи є дебоунс
//   static unsigned long tmr = 0;     // Таймер
//   pinState = digitalRead(BUTTON);   // Зчитати значення кнопки
//   if (pinState == LOW && previviousState == HIGH) // Клік
//   {
//     Serial.println("Клік");
//     if(deb == 0)                   // Вклюсити дебоунс 
//     {
//       deb = 1;
//       tmr = millis();              // Встановити початкове значення таймеру на теперішній час
//     }
//   }
//   if (deb == true && (millis() - tmr > 100))      // Якщо пройшов певний час і кнопка далі натиснута
//   {
//     ledState = !ledState;           // Інвертувати стан світлодіода
//     deb = 0;
//   }
//   if(pinState == HIGH)              // Кнопка відпущена
//   {
//     deb = 0;
//   }
//   previviousState = pinState;       // Зберегти попередній стан
//   digitalWrite(LED, ledState);      // Міняємо стан світлодіода
// }

// Проста програма
/*
void loop() {
  // put your main code here, to run repeatedly:
  static bool pinState = 0;         // Зміння, в яку буде записано значення з кнопки
  pinState = digitalRead(BUTTON);   // Зчитати значення кнопки
  digitalWrite(LED, !pinState);     // Міняємо стан світлодіода
}
*/