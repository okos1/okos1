/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

#include "rs485.h"



// constants won't change. They're used here to
// set pin numbers:
const int buttonPin2 = 2;     // the number of the pushbutton pin
const int buttonPin3 = 3;     // the number of the pushbutton pin
const int buttonPin4 = 4;     // the number of the pushbutton pin
const int buttonPin5 = 5;     // the number of the pushbutton pin

const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

int integer;
void setup() {
  Serial.begin(9600);

  
  Serial.println("YourDuino.com SoftwareSerial remote loop example");
  Serial.println("Use Serial Monitor, type in upper window, ENTER");

  
  pinMode(ledPin, OUTPUT);
  

  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);

  setup_rs485();




  
}

void loop() {

/*
    digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit
    for(int i=0;i<250;i++){  
      //digitalWrite(ledPin, HIGH); 
      RS485Serial.write(i);          // Send byte to Remote Arduino
      Serial.println(i);
      //digitalWrite(ledPin, LOW);  // Show activity    
      delay(100);
    }
    digitalWrite(SSerialTxControl, RS485Receive);  // Disable RS485 Transmit       
*/

  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);

  if (buttonState2 == HIGH) { // turn LED on:    
    ledstrip("1");
  } else {                    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  
  if (buttonState3 == HIGH) { // turn LED on:    
    ledstrip("2");
  } else {                    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

/*
  if (buttonState4 == HIGH) { // turn LED on:    
    ledstrip("3");
  }else {                    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  
  if (buttonState5 == HIGH) { // turn LED on:    
    ledstrip("4");
  }else {                    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
*/  
/*

  //digitalWrite(ledPin, HIGH);  // Show activity
  if (Serial.available()){
    byteReceived = Serial.read();
    Serial.print("kuld ->");
    Serial.print(byteReceived);
    Serial.println();
    
    digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit   
    RS485Serial.write(byteReceived);          // Send byte to Remote Arduino
    Serial.println("elkuldve");
    digitalWrite(ledPin, LOW);  // Show activity    
    //delay(10);
    digitalWrite(SSerialTxControl, RS485Receive);  // Disable RS485 Transmit  
     
  }

*/
/*  
 // delay(100);
  if (RS485Serial.available()){  //Look for data from other Arduino VESZ VMIT
    digitalWrite(ledPin, HIGH);  // Show activity
    integer = RS485Serial.read();    // Read received byte
    Serial.print("back-");
    Serial.write(integer);
    //Serial.write(integer);        // Show on Serial Monitor
    Serial.println();
   // delay(100);
    digitalWrite(ledPin, LOW);  // Show activity   
   }else{
    //Serial.println("vételre kész állapotvab van");
   }
*/
}

void ledstrip(String szin){
    digitalWrite(ledPin, HIGH);
    digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit  
    //RS485Serial.print("*-+ 11"+szin+"4,*-+ 21"+szin+"4,*-+ 31"+szin+"4,*-+ 41"+szin+"4");
    RS485Serial.print("*-+ B1"+szin+"4,*-+ A1"+szin+"4,*-+ 91"+szin+"4,*-+ 81"+szin+"4");
    //RS485Serial.write(64);
    Serial.write(64);
    Serial.println("elott kuld ->4");
    delay(500);
/*    
    Serial.println("utan kuld ->4");
    digitalWrite(SSerialTxControl, RS485Receive);  // Disable RS485 Transmit  
    delay(1000);
*/
    
}

