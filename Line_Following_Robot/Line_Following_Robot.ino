//Distances from the centroid of the robot to the centre of each sensor in mm
//#include <ENGG1500Lib.h>
/*
 State 0 = Line Following
 State 1 = Wall Turning State
 State 2 = Where the fuck is line 
 State 3 = Look for Corridor
 State 4 = Follow Corridor
 State 5 = Right Turn
 State 6 = Garage
 */
#define LeftMotor 5
#define RightMotor 6
#define ECHO 12
#define TRIG 7

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
int state = 0;
int StandardSpeed = 80;
int SpeedDifference = 0;
int RestSpeed = 0;
float den;
float num;
unsigned long timer;

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
     pinMode(8,OUTPUT); //set IN1 as an output
     pinMode(9,OUTPUT); //set IN2 as an output
     pinMode(10,OUTPUT); //set IN3 as an output
     pinMode(11,OUTPUT); //set IN4 as an output
     pinMode(ECHO, INPUT);
     pinMode(TRIG, OUTPUT);
     
     Serial.begin(9600);
     delay(2000);
}
void loop() { 

distance_mm = sonar_mm();  
  if(state == 0){
    LineFollowing();
  }
  /*if(distance_mm < 50){
    analogWrite(5,0);
    analogWrite(6,0);
    //delay(5000);
    state = 1;
  }*/
  if ( state == 1){
    Wall_to_Turn();
  }
  if(state == 2){
    Where_the_fuck_is_the_line();
  }
  if (state == 4){
    stoppystate();
  }
    
  
}
