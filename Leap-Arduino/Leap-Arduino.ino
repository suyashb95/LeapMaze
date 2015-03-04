#include<Servo.h>

Servo MyServo1,MyServo2;
char input1,input2,input3;
int count = 0;
const int buttonPin = 8;  

//Inner servo : 50 (MyServo2)
//Outer Servo : 35 (MyServo1)
void setup()
{
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  MyServo1.attach(9);    
  MyServo2.attach(10);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
//MyServo.writeMicroseconds(500);
  MyServo1.write(35);
  MyServo2.write(50);
  delay(500);
  MyServo1.detach();
  MyServo2.detach();
}

void loop()
{  
  
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {     
    // turn LED on:    
  MyServo1.write(35);
  MyServo2.write(50);
  MyServo2.detach();
  } 
  else 
  {
  MyServo1.attach(9);
  MyServo2.attach(10);    
  while(Serial.available()>2)
  {
    input1= Serial.read();
    if(input1 == 60)
    {
      input2 = Serial.read();  //Pitch
      input3 = Serial.read();  //Roll
      //MyServo.write(500 + (2./5*(input/2.8)));
      if(!(((35 + input2/5) >= 45) || ((35 + input2/5 <=25))))
        MyServo1.write(35 + input2/5);
        delay(2);
      if(!((( 50 + input3/5) >= 60) || ((50 + input3/5 <=35))))
        MyServo2.write(50 + input3/5);
        delay(2);
    }

  }
  }
}
