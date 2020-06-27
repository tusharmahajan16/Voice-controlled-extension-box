#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; 
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

  if(readvoice == "both switch on")
  {
    digitalWrite(3, LOW);
    digitalWrite (4, LOW);
 
    delay(100);
  }

  else if(readvoice == "both switch off")
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);

    delay(100);
  }

  else if (readvoice == "first switch on")
  {
    digitalWrite (3, LOW);
   delay (100);
  
  }

 else if ( readvoice == "second switch on")
 {
   digitalWrite (4, LOW);
    delay(100);
 }

 else if (readvoice == "first switch off")
 {
   digitalWrite (3, HIGH );
   delay (100);
 }
 else if (readvoice == "second switch off")
 {
   digitalWrite (4, HIGH);
   delay (100);
 }
  

 readvoice="";}} //Reset the variable
