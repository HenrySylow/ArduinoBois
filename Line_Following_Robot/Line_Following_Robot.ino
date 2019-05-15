#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <ENGG1500Lib.h>

 /*
 State 0 = Line Following
 State 1 = Wall Turning State
 State 2 = Where the fuck is line 
 State 3 = Look for Corridor
 State 4 = Follow Corridor
 State 5 = Right Turn
 State 6 = Garage
 State 7 = Gate
 */
 
#define LeftMotor 5
#define RightMotor 6
#define ECHO 12
#define TRIG 7

//Line Following Variables
float x1 = -22.5;
float x2 = -7.5;
float x3 = 7.5;
float x4 = 22.5;
float w1;
float w2;
float w3;
float w4;
float LineDistance;
unsigned int distance_mm;
int StandardSpeed = 80;
int SpeedDifference = 0;
int RestSpeed = 0;
float den;
float num;

//Misc Variables
unsigned long timer;
int state = 0;

//RGB Sensor Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;

void setup() {
     //IR sensors`
     pinMode(A0, INPUT);//IR front
     pinMode(A1, INPUT);//IR front
     pinMode(A2, INPUT);//IR front
     pinMode(A3, INPUT);//IR front
     
     //Motor Speed
     pinMode(5,OUTPUT); //set ENA as an output
     pinMode(6,OUTPUT); //set ENB as an output
     
     //Motor directions
     pinMode(8,OUTPUT); //set IN1 as an output, 
     pinMode(9,OUTPUT); //set IN2 as an output
     pinMode(10,OUTPUT); //set IN3 as an output
     pinMode(11,OUTPUT); //set IN4 as an output

     //Ultrasonic Sensor
     pinMode(ECHO, INPUT); 
     pinMode(TRIG, OUTPUT);

     //Servo 
     //pinMode();
     //pinMode();

     //RGB Sensor
     //pinMode();
     //pinMode();

     //Check for RGB working

     /*if ( apds.init() ) {
      //flash LED to signal RGB sensor on
     }

     //delay between flashes

     if ( apds.enableLightSensor(false) ) {
      //flash to signal light sensor on
     }*/
     
     Serial.begin(9600);
     delay(2000); //gives time for things to setup
}
void loop() { 

distance_mm = sonar_mm();

  /*if(distance_mm < 50){
    analogWrite(5,0);
    analogWrite(6,0);
    //delay(5000);
    state = 1;
  }*/
  if(red_light >= 200) {
    state = 7;
  }
  if(state == 0){
    LineFollowing();
  }
  if ( state == 1){
    Wall_to_Turn();
  }
  if(state == 2){
    Where_the_fuck_is_the_line();
  }
  if (state == 4){
    stoppystate();
  }
  if (state == 7) {
    Gate();
  }
  
}


