int trigger = 7;
int echo = 8;
int led = 13;
int temp = A0;
int value;
int buzzer=12;
void setup()
{
 Serial.begin(9600);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(led,OUTPUT);
 pinMode(buzzer,OUTPUT);
}
void loop()
{
 value = analogRead(temp);
 float mv = ( value/1024.0)*5000;
 float cl = mv/10;
 float fh = (cl*9)/5 + 32;
 Serial.print("temperature = ");
 Serial.print(cl);
 Serial.print("*C");
 Serial.println();
 delay(1000);
 digitalWrite(trigger,LOW);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 float duration = pulseIn(echo,HIGH);
 float distance = (duration*0.0343)/2;
 Serial.print("Distance=" );
 Serial.println(distance);
 if (distance>=100)
 {
 digitalWrite(led,HIGH);
 digitalWrite(buzzer,HIGH);
 }
 else
 {
 digitalWrite(led,LOW);
 digitalWrite(buzzer,LOW);
 }
} 