
#include <Adafruit_Circuit_Playground.h>

#include <SoftwareSerial.h>
#include <Servo.h>
#include <DHT.h>
dht DHT;
int buzzerPin = 5;
#define DHT11_PIN 6
SoftwareSerial mySerial(8, 7);
String sicaklik;
String nem;
String hareket;
Servo kapi, garaj;
int lamba = 11;
int salon = 13;
int garajlamba = 12;
int pir = 2;
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  kapi.attach(9);
  garaj.attach(10);
  pinMode(lamba, OUTPUT);
  pinMode(garajlamba, OUTPUT);
  pinMode(salon, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(9, OUTPUT);
  kapi.write(90);
  garaj.write(90);

}

void loop()
{



  nem = "+";
  sicaklik = "$";
  hareket = "-";

  int chk = DHT.read11(DHT11_PIN);
  int n = DHT.humidity;
  int s = DHT.temperature;


  nem += n;
  nem += "~";
  sicaklik += s;
  sicaklik += "~";

  int deger = digitalRead(pir);
  if (deger == 1) {
    digitalWrite(garajlamba, HIGH);
    tone(buzzerPin, 523);
  } else {
    digitalWrite(garajlamba, LOW);
    noTone(buzzerPin);
  }
  hareket += deger;
  hareket += "~";

  if (mySerial.available() > 0) {
    char kar = mySerial.read();
    Serial.println(kar);
    if (kar == 'K') {
      kapi.write(175);
      delay(15);
      digitalWrite(9, LOW);
    } else if (kar == 'k') {
      kapi.write(10);
    } else if (kar == 'G') {
      garaj.write(175);
    } else if (kar == 'g') {
      garaj.write(10);
    } else if (kar == 'L') {
      digitalWrite(lamba, HIGH);
    } else if (kar == 'l') {
      digitalWrite(lamba, LOW);
    } else if (kar == 'S') {
      digitalWrite(salon, HIGH);
    } else if (kar == 's') {
      digitalWrite(salon, LOW);
    } else if (kar == 'O') {
      mySerial.print(nem);
      delay(10);
      mySerial.print(sicaklik);
      delay(10);
      mySerial.print(hareket);
      delay(10);
      mySerial.print(nem);
      delay(10);
      mySerial.print(sicaklik);
      delay(10);
      mySerial.print(hareket);
      delay(10);  mySerial.print(nem);
      delay(10);
      mySerial.print(sicaklik);
      delay(10);
      mySerial.print(hareket);
      delay(10);
    }
  }

}
