#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(A8, 38); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)
//
int en1 = 2;
int a1 = 3;
int a2 = 4;
//
int en2 = 7;
int b1 = 6;
int b2 = 5;
//
int en3 = 8;
int c1 = 9;
int c2 = 10;
//

int en4 = 13;
int d1 = 12;
int d2 = 11;

int dataIn;
int lbw[50], lfw[50], rbw[50], rfw[50]; // for storing positions/steps
int index = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(en3, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(en4, OUTPUT);
  Serial.begin(9600);
  Bluetooth.begin(9600); // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(1);
  delay(20);

}

void loop() {
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.read();  // Read the data
    Serial.println(dataIn);
    if (dataIn == 0) {
      sagondur();
      sagarkadur();
      solondur();
      solarkadur();
    }
    if (dataIn == 1) {
      solondur();
      solarka();
      sagon();
      sagarkadur();

    }
    if (dataIn == 2) {
      sagarka();
      sagon();
      solarka();
      solon();
    }
    if (dataIn == 3) {
      solon();
      solarkadur();
      sagondur();
      sagarka();


    }
    if (dataIn == 4) {
      solongeri();
      solarka();
      sagon();
      sagarkageri();
    }
    if (dataIn == 5) {

      solon();
      solarkageri();
      sagongeri();
      sagarka();

    }
    if (dataIn == 6) {
      solongeri();
      solarkadur();
      sagondur();
      sagarkageri();

    }
    if (dataIn == 7) {
      sagarkageri();
      sagongeri();
      solarkageri();
      solongeri();

    }
    if (dataIn == 8) {
      solondur();
      solarkageri();
      sagongeri();
      sagarkadur();

    }
    if (dataIn == 9) {
      solongeri();
      solarkageri();
      sagon();
      sagarka();
    }
    if (dataIn == 10) {
      solon();
      solarka();
      sagongeri();
      sagarkageri();
    }
    if (dataIn == 11) {

    }
    if (dataIn == 12) {

    }
    if (dataIn == 14) {

    }


  }
}

void sagon () {
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  analogWrite(en4, 250);
}
void sagarka() {
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(en2, 250);
}
void solon () {
  digitalWrite(c1, HIGH);
  digitalWrite(c2, LOW);
  analogWrite(en3, 250);
}
void solarka () {
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(en1, 250);
}


void sagondur () {
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  analogWrite(en4, 0);
}
void sagarkadur() {
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(en2, 0);
}
void solondur () {
  digitalWrite(c1, HIGH);
  digitalWrite(c2, LOW);
  analogWrite(en3, 0);
}
void solarkadur () {
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(en1, 0);
}

void sagongeri () {
  digitalWrite(d2, HIGH);
  digitalWrite(d1, LOW);
  analogWrite(en4, 250);
}
void sagarkageri() {
  digitalWrite(b2, HIGH);
  digitalWrite(b1, LOW);
  analogWrite(en2, 250);
}
void solongeri () {
  digitalWrite(c2, HIGH);
  digitalWrite(c1, LOW);
  analogWrite(en3, 250);
}
void solarkageri () {
  digitalWrite(a2, HIGH);
  digitalWrite(a1, LOW);
  analogWrite(en1, 250);
}
