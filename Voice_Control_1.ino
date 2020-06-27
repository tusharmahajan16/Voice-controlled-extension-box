#include <SoftwareSerial.h>
String value;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);       // start serial communication at 9600bps
  bluetooth.begin(9600);
}

void loop() {
  Serial.println(value);
 if (bluetooth.available())
   {
    value = bluetooth.readString();

    if (value == "All Switches On"){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);  
      }

    if (value == "All Awitches Off"){
      digitalWrite(9, LOW); 
      digitalWrite(10, LOW);       
      }

    if (value == "Switch 1 On"){
    digitalWrite(9, HIGH); 
      }

    if (value == "Switch 2 On"){
      digitalWrite(10, HIGH);       
      }
      
    if (value == "switch 1 Off"){
    digitalWrite(9, LOW); 
      }

    if (value == "Switch 2 Off"){
      digitalWrite(10, LOW);       
      }

 }

}
