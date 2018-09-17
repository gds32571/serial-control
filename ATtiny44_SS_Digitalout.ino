/*
  Serial to pin 2
  receives serial data on pin 2 and turns on/off digital pin
  First character is pin, second character is state: 0 or 1 
  Must delay 1/2 second after sending string before sending another.
  16 Sept 2018 - gswann

*/

// Runs on Attiny44, also ATTiny 85 if you change the pins
#define led 6    // package pin 10

char c ;

#define delayval 500

#include <SoftwareSerial.h>
//SoftwareSerial mySerial(3,4); // RX, TX  package pins 2 and 3  -  ATTiny85
SoftwareSerial mySerial(10, 9); // RX, TX  package pins 2 and 3  -  ATTiny44

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  mySerial.begin(300);
  mySerial.listen();
  delay(delayval);
  char x = 0;
  while (x != '\n'){
    x = getChar();
  }
  
}

// chars are -128 to 127
char getChar() {
  char c = -1;
  while (c == -1 ) {
    c = mySerial.read();
  }
  return c;
}

void loop() {

  char pin = getChar();
  char state = getChar();
  char newline = getChar();

  mySerial.print(pin);
  mySerial.print(" ");
  mySerial.println(state);
  pin = pin - 0x30;
  state = state - 0x30;
  
  if (pin >= 0 && pin <= 5) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin,state);
  }
  delay(10);
}

