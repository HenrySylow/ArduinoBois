void leftForwards(void) 
{
    digitalWrite(8,LOW); //IN1
    digitalWrite(9,HIGH); //IN2
}
void leftBackwards(void) 
{
    digitalWrite(8,HIGH); //IN1
    digitalWrite(9,LOW); //IN2
}
void rightForwards(void) 
{
    digitalWrite(10,LOW); //IN3
    digitalWrite(11,HIGH); //IN4
}
void rightBackwards(void) 
{
    digitalWrite(10,HIGH); //IN3
    digitalWrite(11,LOW); //IN4
}