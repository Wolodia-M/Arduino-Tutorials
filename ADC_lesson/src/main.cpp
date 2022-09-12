#include <Arduino.h>

#define POT A5    // Пін, на який підключено потенціометр
#define LED A1    // Пін, на який підключено світлодіод
#define VALUE 400
#define TRESHOLD 100

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);     // Почати передачу по послідовному порту
  pinMode(POT, INPUT);    // Вставити пін як вхід
  pinMode(LED, OUTPUT);
}

// Зчитати знаяення з АЦП і вивести у термінал та включити світлодіод у певному діапазоні значень
void loop() {
  int value = 0;              // Створення змінної
  value = analogRead(POT);    // Зчитати аналогове значення з піна
  Serial.println(value);    // Вивести значення у послідовний порт
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