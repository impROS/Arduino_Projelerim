#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"           //Modül ile ilgili kütüphaneleri ekliyoruz
int mesaj[1];
RF24 alici(7, 8);
const uint64_t kanal = 0xE8E8F0F0E1LL;
int led = 2;

void setup(void) {
  Serial.begin(9600);

  alici.begin();
  alici.openReadingPipe(1, kanal);
  alici.startListening();
  pinMode(led, OUTPUT);
}

void loop(void) {
  // Serial.println("loop");
  delay(10);
  digitalWrite(led, LOW);
  if (alici.available())
  {
          Serial.println("if 123");
    if (mesaj[0] == 123)
    {
      Serial.println("if 123");

      digitalWrite(led, HIGH);
      delay(100);
    }
  } 
}

