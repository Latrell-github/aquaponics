#include <LiquidCrystal_I2C.h>

#include <SD.h>
#include <SPI.h>

#include <Wire.h>

#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

SoftwareSerial Nodemcu_SoftSerial(7,8); //RX TX



long duration, inches;
int set_val, percentage; //water level
bool state,pump;
int sensor_pin = A0; // Soil Moisture sensor
int output_value; //read soil moisture
int relayPin = 4; //soil moisture to pump relay


int gate=11; //temp sensor
volatile unsigned long tempduration=0;
unsigned char i[5];
unsigned int j[40];
unsigned char value=0;
unsigned answer=0;
int z=0;
int b=1;

//init phsensor
float calibration_value = 21;
int phval = 0;
float ph_act;

int ppumpin = 5; //peristaltic pump
unsigned long int avgval;
int buffer_arr[10], temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Nodemcu_SoftSerial.begin(9600);
  // initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  //declare pinmode
  //pinMode(pinCS, OUTPUT);
  pinMode (2, OUTPUT); //ultrasonic trigger pin
  pinMode(3, INPUT); //ultrasonic echo pin
  pinMode(6, OUTPUT); //ultrasonic to pump relay
  pinMode(sensor_pin, INPUT);
  pinMode(relayPin, OUTPUT);

  set_val=EEPROM.read(0);
  if(set_val>20)set_val=20;



}

void loop() {
  // put your main code here, to run repeatedly:


  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();
  
  //waterlevel
  water_level();
  //assign collect data from water level function to JSON object
  data["Water Level"] = percentage;

  //soil sensor
  soil_sensor();
  //assign collect data from soil sensor function to JSON object
  data["Soil"] = output_value;

  //temperatuure and Humidity
 //dht11();
  //assign collect data from dht11 function to JSON object
  //data["Temperature"] = i[2];
  //data["Humidity"]  = i[0];
   
 //ph sensor
  ph_balancer();
  //assign collect data from ph_balancer function to JSON object
 data["ph Level"] = ph_act;

  //send all data to Nodemcu
  data.printTo(Nodemcu_SoftSerial);
  jsonBuffer.clear();

  //lcd display
 lcd_display();

} 



  
