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
     SpeedDifference = LineDistance*7;
     /*Serial.print("Num: ");
     Serial.println(num);
     Serial.print("Den: ");
     Serial.println(den);
     Serial.print("w1 ");
     Serial.println(w1);
     Serial.print("w2 ");
     Serial.println(w2);
     Serial.print("w3 ");
     Serial.println(w3);
     Serial.print("w4 ");
     Serial.println(w4);*/
     if (den<180){
      unsigned long current_time=millis();
      unsigned long timer = current_time + 2000;
      State = 2;// State is where the fuck is the line function;      
     }
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

void Wall_to_Turn() {
  
  analogWrite(5, RestSpeed);
  analogWrite(6, RestSpeed);
  delay(800);
  leftForwards();
  rightBackwards();
  analogWrite(5, 100);
  analogWrite(6, 100);
  delay(500);
  analogWrite(5, RestSpeed);
  analogWrite(6, RestSpeed);
  delay(100);
  State = 1;
   
  
}



/*
 THINGS TO_DO:

 SHARP CORNER
 
 STOP IN THE SHED
 
 CORRIDOR
 
 GATE
 
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

void Where_the_fuck_is_the_line() {
     
     leftForwards();
     rightForwards(); 
     w1 = analogRead(A0);
     w2 = analogRead(A1);
     w3 = analogRead(A2);
     w4 = analogRead(A3);
     num=(w1*x1) + (w2*x2) + (w3*x3) + (w4*x4);
     den= w1 + w2 + w3 + w4;
     LineDistance = num/den;
     SpeedDifference = LineDistance*7;
     /*Serial.print("Num: ");
     Serial.println(num);
     Serial.print("Den: ");
     Serial.println(den);
     Serial.print("w1 ");
     Serial.println(w1);
     Serial.print("w2 ");
     Serial.println(w2);
     Serial.print("w3 ");
     Serial.println(w3);
     Serial.print("w4 ");
     Serial.println(w4);*/
     if (den<180 && millis()>timer){
//          state = 4;             
     }
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

 






