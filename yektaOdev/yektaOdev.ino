int inputPin = 2;
int val = 0;
int sayac = 0;

unsigned long eskiZaman = 0;
unsigned long yeniZaman;
unsigned long gecenSure = 0;

void setup() {

  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);

  if (val == HIGH) {
    sayac++;
    if (sayac == 20) {
      yeniZaman = millis();
      gecenSure=yeniZaman-eskiZaman;
      eskiZaman = yeniZaman;
      sayac=0;
    }
  }
}


///////////////////////

