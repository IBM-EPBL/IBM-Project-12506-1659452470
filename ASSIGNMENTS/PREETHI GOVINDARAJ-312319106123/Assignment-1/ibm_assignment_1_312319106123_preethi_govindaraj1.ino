// IBM Assignment-1 312319106123- Preethi Govindaraj //
int pirsensor= 0;
int trigger= 12;
int led= 8;
int echo= 11;
long duration= 0;
int cm= 0;
int inch= 0;
int gas= A2;

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(2, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  pirsensor= digitalRead(2);
  digitalWrite(trigger, LOW);
  digitalWrite(trigger, HIGH);
  digitalWrite(trigger, LOW);
  
  duration= pulseIn(echo, HIGH);
  cm= duration*0.030/2;
  inch= duration*0.0133/2;
  
  if (pirsensor == HIGH)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  delay(10);
  
  if(inch<50)
  {
        digitalWrite(led, HIGH);
  }
  else
  {
        digitalWrite(led, LOW);
  }
  if(inch<30)
  {
    Serial.print("Inch: ");
    Serial.println(inch);
    Serial.print("CM: ");
    Serial.println(cm);
  }
  delay(500);
  
  gas= analogRead(A2);
  if(gas>500)
  {
    digitalWrite(9, LOW);
    tone(6,255,1000);
    Serial.println("Smoke detected");
  }
  else
  {
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
  }
  
}