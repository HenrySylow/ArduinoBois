//Distances from the centroid of the robot to the centre of each sensor in mm
//#include <ENGG1500Lib.h>
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
int State = 1;
int StandardSpeed = 80;
int SpeedDifference = 0;
float den;
float num;

void setup() {
     //IR sensors
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
     
     Serial.begin(115200);
     delay(5000);
}
void loop() {
  if(sonar_mm < 100){
    State = 2;
  }
  if( State = 1) {
    LineFollowing();
  }
  /*else if ( State = 2 ) {
    WallAssesment();
    
  }*/
}



/*void WallAssement(){
  for
  leftForwards();
  rightBackwards();
  
}*/






void LineFollowing() {
     
     leftForwards();
     rightForwards(); 
     w1 = analogRead(A0);
     w2 = analogRead(A1);
     w3 = analogRead(A2);
     w4 = analogRead(A3);
     num=(w1*x1) + (w2*x2) + (w3*x3) + (w4*x4);
     den= w1 + w2 + w3 + w4;
     LineDistance = num/den;
     SpeedDifference = LineDistance*8;

     if(SpeedDifference<0){
          SpeedDifference = -SpeedDifference;
     }
     if(SpeedDifference>StandardSpeed){
          SpeedDifference = StandardSpeed;
     }
    
     if(LineDistance>-0.5){//right
          analogWrite(6, StandardSpeed + SpeedDifference);
          analogWrite(5, StandardSpeed - SpeedDifference);
     }
     else if(LineDistance<+0.5){
          analogWrite(6, StandardSpeed - SpeedDifference);
          analogWrite(5 , StandardSpeed + SpeedDifference);
     }
     else{
     
          analogWrite(5, StandardSpeed);
          analogWrite(6, StandardSpeed);
     }

}
unsigned int sonar_mm(void){
long duration = 0;
const float speed_sound = 340.29;
digitalWrite(TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG, LOW);
duration = pulseIn(ECHO, HIGH); 
return (unsigned int)(0.5 * duration * 1e-6 * speed_sound * 1e3); //Refer to Lab 3
}
