#include <SoftwareSerial.h>

SoftwareSerial rxSerial(2, 3); // RX, TX
// Inputs of Motor A
int in1 = 6;                           // Assign Pin 8 for in1 (Input 1 for Motor A)
int in2 = 5;                           // Assign Pin 7 for in2 (Input for Motor A)
// Inputs of Motor B
int in3 = 9;                           // Assign Pin 5 for in3 ( Input for Motor B)
int in4 = 10;                          // Assign Pin 4 for in4 (Input for Motor B)
long d_time = 2000;
 
int command;             //Int to store app command state.
int speedCar = 130;       // 50 - 255.
int speedCar1 = 90;     // 50 - 255.

int speed_Coeff = 4;



void setup()
{
  Serial.begin(9600);
  rxSerial.begin(9600);
  rxSerial.println("OK"); 
  pinMode(in1, OUTPUT);                           // Pin 5 acts as Output Pin for Motor Input 1 (Motor A)
  pinMode(in2, OUTPUT);                           // Pin 6 acts as Output Pin for Motor Input 2 (Motor A)
  pinMode(in3, OUTPUT);                           // Pin 9 acts as Output Pin for Motor Input 3 (Motor B)
  pinMode(in4, OUTPUT);                           // Pin 10 acts as Output Pin for Motor Input 4 (Motor B)
  // Motor A
  analogWrite(in1, 0);                            // Pin 8 is High for Motor Input1
  analogWrite(in2, 0);                            // Pin 7 is Low for Motor Input2

  // Motor B
  analogWrite(in3, 0);                            // Pin 5 is High for Motor Input 3
  analogWrite(in4, 0);                            // Pin 4 is Low for Motor Input 4

}

void forward()
{
   analogWrite(in1, speedCar1);
   analogWrite(in2, 0);
   analogWrite(in3, speedCar);
   analogWrite(in4, 0);
   Serial.println("ForWord");
}

void backward()
{
   analogWrite(in1, 0);
   analogWrite(in2, speedCar1);
   // Set Motor B backward
   analogWrite(in3, 0);
   analogWrite(in4, speedCar);
   Serial.println("BackWord");
}

void left()
{
   // Move Left
   // Set Motor A backward
   analogWrite(in1, speedCar1);
   analogWrite(in2, 0);
   // Set Motor B backward
   analogWrite(in3, 0);
   analogWrite(in4, speedCar);
   Serial.println("Left");
}

void right()
{
   // Move Right
   // Set Motor A backward
   analogWrite(in1, 0);
   analogWrite(in2, speedCar1);
   // Set Motor B backward
   analogWrite(in3, speedCar);
   analogWrite(in4, 0);
   Serial.println("Right");
}
void stop_motor()
{
  analogWrite(in1, 0);                            // Pin 8 is High for Motor Input1
  analogWrite(in2, 0);                             // Pin 7 is Low for Motor Input2
  analogWrite(in3, 0);                           // Pin 5 is High for Motor Input 3
  analogWrite(in4, 0);                            // Pin 4 is Low for Motor Input 4
  Serial.println("STOP");
}

void loop()
{

if (rxSerial.available() > 0) 
  {
    command = rxSerial.read();
    Serial.print(command);
    
  switch (command) 
  {
    
    case 'F':forward();break;
    case 'B':backward();break;
    case 'L':left();break;
    case 'R':right();break;
    case 'S':stop_motor();break;
  }
  }
}
/*End*/
