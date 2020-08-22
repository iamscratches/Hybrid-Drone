int motor1Left = 5;// defines pin 5 as connected to the motor
int motor1Right= 6;// defines pin 6 as connected to the motor
int motor2Left = 7;// defines pin 7 as connected to the motor
int motor2Right = 8;// defines pin 8 as connected to the motor
int enA = 9;//represents y-axis channel2 motorSpeedA
int enB = 10;//represents x-axis channel1
int ch1 = 3; // defines the channels that are connected
int ch2 = 11;// to pins 2 and 3 of arduino respectively

int Channel1 ; // Used later to 
int Channel2 ; // store values
void  setup ()

{
   pinMode (motor1Left, OUTPUT);// initialises the motor pins
   pinMode (motor1Right, OUTPUT);
   pinMode (motor2Left, OUTPUT);
   pinMode (motor2Right, OUTPUT);// as outputs
   pinMode (ch1, INPUT);// initialises the channels
   pinMode (ch2, INPUT);// as inputs
   Serial.begin (9600); // Sets the baud rate to 9600 bps
}

void  loop ()
{
  //Serial.println("Start");
  
  //Serial.println (Channel1); //Prints the channels value on the serial monitor
  // Channel2 = (pulseIn (ch2, HIGH)); // Checks the value of channel1
  //Serial.println (Channel2); //Prints the channels value value on the serial monitor
 // Serial.println(Channel1);
  //Serial.println(Channel2);

  int motorSpeedA = 0 ;
  int motorSpeedB = 0 ;

  /*if (Channel1 > 1487 && Channel1 < 1542 ) 
  {
    digitalWrite (motor1Left, LOW); // Sets both the
    digitalWrite (motor1Right, LOW);// motors to low
  }*/
  Channel1 = (pulseIn (ch1, HIGH)); // Checks the value of channel1
  Channel2 = (pulseIn (ch2, HIGH)); // Checks the value of channel1
  if (Channel1 < 1300 && Channel2>1300 && Channel2<1700 ) // Checks if Channel1 is lesser than 1300
  {
    
    digitalWrite (motor1Left, LOW);// Turns the right
    digitalWrite (motor1Right, HIGH);// motor forward
    digitalWrite (motor2Left, LOW);// Turns the right
    digitalWrite (motor2Right, HIGH);// motor forward
    /*Serial.println("motor1Left, HIGH");
    Serial.println("motor1Right, LOW");
    Serial.println("motor2Left, HIGH");
    Serial.println("motor2Right, LOW");*/
    motorSpeedA = map(Channel1, 1470, 970, 0, 1023);
    motorSpeedB = map(Channel1, 1470, 970, 0, 1023);
    /*Serial.println("motorSpeedA");
    Serial.println(motorSpeedA);
    Serial.println("motorSpeedB");    
    Serial.println(motorSpeedB);*/
    
    
  }
  else if (Channel1 > 1700 && Channel2>1300 && Channel2<1700 ) // Checks if Channel1 is greater than 1500
  {
    digitalWrite (motor1Left, HIGH);// Turns the left
    digitalWrite (motor1Right, LOW); // motor forward
    digitalWrite (motor2Left, HIGH);// Turns the left
    digitalWrite (motor2Right, LOW); // motor forward
    
    motorSpeedA = map(Channel1, 1500, 2000, 0, 1023);
    motorSpeedB = map(Channel1, 1500, 2000, 0, 1023);
  }/*
  else{
    digitalWrite (motor1Left, HIGH);// Turns the left
    digitalWrite (motor1Right, HIGH); // motor forward
    digitalWrite (motor2Left, HIGH);// Turns the left
    digitalWrite (motor2Right, HIGH); // motor forward
    motorSpeedA = 0;
    motorSpeedB = 0;
  }*/
  
  //Serial.println (Channel2); //Prints the channels value value on the serial monitor

  /*if (Channel2 > 1430 && Channel2 < 1599 ) // If these conditions are true, do the following
  {
    digitalWrite (motor2Left, LOW);// Sets both the
    digitalWrite (motor2Right, LOW);// motors to low
  }*/

  else if (Channel2 < 1300 && Channel1>1300 && Channel1<1700 ) // Checks if Channel2 is lesser than 1300
  {
    digitalWrite (motor1Left, LOW);// Turns the left
    digitalWrite (motor1Right, HIGH);// motor backward
    digitalWrite (motor2Left, HIGH);// Turns the left
    digitalWrite (motor2Right, LOW);// motor backward
    int xMapped = map(Channel2, 1470, 970, 0, 1023);
    motorSpeedA = motorSpeedA - xMapped ;
    motorSpeedB = motorSpeedB + xMapped ; 
    if (motorSpeedA < 0)
      motorSpeedA=0;
    if (motorSpeedB > 1023)
      motorSpeedB=1023;
  }
    

  
  else if (Channel2 > 1500) // Checks if Channel2 is greater than 1500
  {
    digitalWrite (motor1Left, HIGH);// Turns the left
    digitalWrite (motor1Right, LOW);// motor backward
    digitalWrite (motor2Left, LOW);// Turns the left
    digitalWrite (motor2Right, HIGH);// motor backward
    int xMapped = map(Channel2, 1500, 2000, 0, 1023);
    motorSpeedA = motorSpeedA + xMapped ;
    motorSpeedB = motorSpeedB - xMapped ;
    if (motorSpeedB < 0)
      motorSpeedB = 0;
    if (motorSpeedA > 1023)
      motorSpeedA = 1023;
  }
    
    /*digitalWrite (motor2Left, HIGH);// Turns the right
    digitalWrite (motor2Right, LOW);// motor backward
    motorSpeedA = map(ch2, 1599, 1982, 0, 1023);*/
  
  if (motorSpeedA < 70)
      motorSpeedA = 0;
  if (motorSpeedB < 70)
      motorSpeedB = 0;
  Serial.println(Channel2);
  delay(200);
  //analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  //analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    /*digitalWrite (motor1Left, HIGH);// Turns the left
    digitalWrite (motor1Right, LOW); // motor forward
    digitalWrite (motor2Left, HIGH);// Turns the left
    digitalWrite (motor2Right, LOW); // motor forward
  Serial.println("motorSpeedA");
  Serial.println(motorSpeedA);
  Serial.println("motorSpeedB");
  Serial.println(motorSpeedB);  */

}
  /*
   * motorcode
   *   Arduino DC Motor Control - PWM | H-Bridge | L298N
         Example 02 - Arduino Robot Car Control
    by Dejan Nedelkovski, www.HowToMechatronics.com

#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
int motorSpeedA = 0;
int motorSpeedB = 0;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void loop() {
  int xAxis = analogRead(A0); // Read Joysticks X-axis
  int yAxis = analogRead(A1); // Read Joysticks Y-axis
  // Y-axis used for forward and backward control
  if (yAxis < 470) {
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
  // If joystick stays in middle the motors are not moving
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
  // X-axis used for left and right control
  if (xAxis < 470) {
    // Convert the declining X-axis readings from 470 to 0 into increasing 0 to 255 value
    int xMapped = map(xAxis, 470, 0, 0, 255);
    // Move to left - decrease left motor speed, increase right motor speed
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }
  if (xAxis > 550) {
    // Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
    int xMapped = map(xAxis, 550, 1023, 0, 255);
    // Move right - decrease right motor speed, increase left motor speed
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  }
  // Prevent buzzing at low speeds (Adjust according to your motors. My motors couldn't start moving if PWM value was below value of 70)
  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}*/
