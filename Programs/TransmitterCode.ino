#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

}

void loop() {
  if(digitalRead(8) == 0){
    Serial.println("Forward");
      const char text[] = "Forward";
  radio.write(&text, sizeof(text));
  delay(50);
  }
  if(digitalRead(6) == 0){
    Serial.println("Backward");
  const char text[] = "Backward";
  radio.write(&text, sizeof(text));
  delay(50);
  }
  if(digitalRead(5) == 0){
    Serial.println("Left");
  const char text[] = "Left";
  radio.write(&text, sizeof(text));
  delay(50);
  }
  if(digitalRead(7) == 0){
    Serial.println("Right");
  const char text[] = "Right";
  radio.write(&text, sizeof(text));
  delay(50);
  }
}