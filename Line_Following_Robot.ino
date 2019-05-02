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
unsigned int distance_mm;
int State = 0;
int StandardSpeed = 80;
int SpeedDifference = 0;
int RestSpeed = 0;
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
     pinMode(ECHO, INPUT);
     pinMode(TRIG, OUTPUT);
     
     Serial.begin(115200);
     delay(2000);
}
void loop() { 
distance_mm = sonar_mm;
Serial.print("Distance");
Serial.println(distance_mm);  
  if(distance_mm < 100){
    analogWrite(5,0);
    analogWrite(6,0);
    delay(5000);
    Wall_to_Turn();
  }
  
  else if( distance_mm>100) {
    LineFollowing();
  }
  
    
  
}


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
    
     if(LineDistance>-0.5){ //vear right
          analogWrite(6, StandardSpeed + SpeedDifference);
          analogWrite(5, StandardSpeed - SpeedDifference);
     }
     else if(LineDistance<+0.5){ //vear left
          analogWrite(6, StandardSpeed - SpeedDifference);
          analogWrite(5 , StandardSpeed + SpeedDifference);
     }
     else{
     
          analogWrite(5, StandardSpeed);
          analogWrite(6, StandardSpeed);
     }

}

void Wall_to_Turn () {
  
  analogWrite(5, RestSpeed);
  analogWrite(6, RestSpeed);
  delay(1000);
  leftForwards();
  rightBackwards();
  analogWrite(5, 100);
  analogWrite(6, 100);
  delay(1300);
  analogWrite(5, RestSpeed);
  analogWrite(6, RestSpeed);
  delay(100);
  State = 1;
   
  
}



/*
 THINGS TO_DO

 SHARP CORNER
 STOP IN THE SHED
 CORRIDOR
 
 */
 void leftForwards(void) {
    digitalWrite(8,LOW); //IN1
    digitalWrite(9,HIGH); //IN2
}
void leftBackwards(void) {
    digitalWrite(8,HIGH); //IN1
    digitalWrite(9,LOW); //IN2
}
void rightForwards(void) {
    digitalWrite(10,LOW); //IN3
    digitalWrite(11,HIGH); //IN4
}
void rightBackwards(void) {
    digitalWrite(10,HIGH); //IN3
    digitalWrite(11,LOW); //IN4
}

unsigned int sonar_mm(void){
long duration = 0;
const float speed_sound = 340.29;// m/s, "const" makes the compiler able to optimise
//... the program where this variable is used, cool!
// Read in a distance from the ultrasonic distance sensor:
// The ultrasonic burst is triggered by a HIGH pulse of 10 microseconds.
digitalWrite(TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG, LOW);
//read length of time pulse
duration = pulseIn(ECHO, HIGH); //This function measures a pulsewidth and returns
//...the width in microseconds
// convert the time into a distance
// the code "(unsigned int)" turns the result of the distance calculation
// into an integer instead of a floating point (decimal or fractional) number.
return (unsigned int)(0.5 * duration * 1e-6 * speed_sound * 1e3);
//"unsigned" ensures we are returning an unsigned number, remember that there is no
//...such thing as negative distance.
}
  

 






