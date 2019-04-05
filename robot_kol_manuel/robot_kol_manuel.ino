#include <Servo.h>

Servo srv_kiskac;
Servo srv_sag_govde;
Servo srv_sol_govde;
Servo srv_ana_govde;

int val_kiskac;
int val_sag_govde;
int val_sol_govde;
int val_ana_govde;

int val_yedek_kiskac;
int val_yedek_sag_govde;
int val_yedek_sol_govde;
int val_yedek_ana_govde;

int pot_kiskac = A3;
int pot_sag_govde = A2;
int pot_sol_govde = A1;
int pot_ana_govde = A0;


void setup() {

  srv_kiskac.attach(9);
  srv_sag_govde.attach(10);
  srv_sol_govde.attach(11);
  srv_ana_govde.attach(8);

  Serial.begin(9600);

}
bool start;
void loop() {
  val_kiskac = analogRead(pot_kiskac);
  val_kiskac = map(val_kiskac, 0, 1023, 0, 180);

  if (val_kiskac < val_yedek_kiskac - 3 || val_kiskac > val_yedek_kiskac + 3) {
    /*
    Serial.println(val_kiskac);
    Serial.println(" - ");
    Serial.println(val_yedek_kiskac);
    srv_kiskac.write(val_kiskac);
    */
    val_yedek_kiskac = val_kiskac;
    Serial.println("kıskac çalıştı");
  }

  val_sag_govde = analogRead(pot_sag_govde);
  val_sag_govde = map(val_sag_govde, 0, 1023, 0, 180);

  if (val_sag_govde < val_yedek_sag_govde - 5 || val_sag_govde > val_yedek_sag_govde + 5) {
   Serial.println(val_sag_govde);
    Serial.println(" - ");
    Serial.println(val_yedek_sag_govde);
    srv_sag_govde.write(val_sag_govde);
    
    srv_sag_govde.write(val_sag_govde);
    val_yedek_sag_govde = val_sag_govde;
    Serial.println("sag çalıştı");
  }

  val_sol_govde = analogRead(pot_sol_govde);
  val_sol_govde = map(val_sol_govde, 0, 1023, 0, 180);

  if (val_sol_govde < val_yedek_sol_govde - 5 || val_sol_govde > val_yedek_sol_govde + 5) {
    srv_sol_govde.write(val_sol_govde);
    val_yedek_sol_govde = val_sol_govde;
    Serial.println("sol çalıştı");
  }


  val_ana_govde = analogRead(pot_ana_govde);
  val_ana_govde = map(val_ana_govde, 0, 1023, 0, 180);

  if (val_ana_govde < val_yedek_ana_govde - 5 || val_ana_govde > val_yedek_ana_govde + 5) {
    srv_ana_govde.write(val_ana_govde);
    val_yedek_ana_govde = val_ana_govde;
    Serial.println("ana çalıştı");
  }

  /*
    val_sag_govde = analogRead(pot_sag_govde);
    val_sag_govde = map(val_sag_govde, 0, 1023, 0, 180);
    srv_kiskac.write(val_sag_govde);

    val_sol_govde = analogRead(pot_sol_govde);
    val_sol_govde = map(val_sol_govde, 0, 1023, 0, 180);
    srv_sol_govde.write(val_sol_govde);

    val_ana_govde = analogRead(pot_ana_govde);
    val_ana_govde = map(val_ana_govde, 0, 1023, 0, 180);
    srv_ana_govde.write(val_ana_govde);
  */

  delay(30);
}
