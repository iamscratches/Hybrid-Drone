#include <Wire.h> 
unsigned long timer;
int address,type;
byte gyro_address ,lowByte;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();             //Start the I2C as master
  Serial.begin(57600);      //Start the serial connetion @ 57600bps
  delay(250);               //Give the gyro time to start 
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.println(F("Searching for MPU-6050 on address 0x68/104"));
  delay(1000);
  if(search_gyro(0x68, 0x75) == 114 ){
    Serial.println(F("MPU-6050 found on address 0x68"));
    gyro_address = 0x68;
  }
  else if(search_gyro(0x69, 0x75) == 0x68){
        Serial.println(F("MPU-6050 found on address 0x69"));
        gyro_address = 0x69;
  }
  else
    Serial.println(F("MPU-6050 not found"));
}
byte search_gyro(int gyro_address, int who_am_i){
  Wire.beginTransmission(gyro_address);
  Wire.write(who_am_i);
  Serial.println(who_am_i);
  Wire.endTransmission();
  Wire.requestFrom(gyro_address, 1);
  timer = millis() + 100;
  while(Wire.available() < 1 && timer > millis());
  lowByte = Wire.read();
  Serial.println(lowByte);
  address = gyro_address;
  return lowByte;
}
