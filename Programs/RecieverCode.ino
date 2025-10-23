#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define enA 2
#define enB 3
#define in1 A0
#define in2 A1
#define in3 A2
#define in4 A3

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if(strcmp(text, "Forward") == 0){
      Serial.println("A");
      digitalWrite(enA, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(enB, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(50);
    }
    if(strcmp(text, "Backward") == 0){
      Serial.println("B");
      digitalWrite(enA, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(enB, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(50);
    }
    if(strcmp(text, "Left") == 0){
      Serial.println("C");
      digitalWrite(enA, HIGH);
      digitalWrite(enB, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(50);
    }
    if(strcmp(text, "Right") == 0){
      Serial.println("D");
      digitalWrite(enA, HIGH);
      digitalWrite(enB, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(50);
    }
    digitalWrite(enA, LOW);
    digitalWrite(enB, LOW);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}