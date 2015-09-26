#define ECHO P1_4
#define TRIG P1_6

int maxRange = 50;
int minRange = 0;
long duration, distance;

void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration/58.2;
  
  if (distance <= maxRange){
    digitalWrite(RED_LED, HIGH);
  }
  else {
    digitalWrite(RED_LED, LOW);
  }
}
