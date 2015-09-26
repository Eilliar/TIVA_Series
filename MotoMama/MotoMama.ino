/*
Project: Control DC Motors using MotMama v.2 (L298N Driver)

Author:Bruno Godoi Eilliar
Date: September 26, 2015.

Notes:
- http://energia.nu/Tutorial_PWM.html
- Motors: http://www.botnroll.com/index.php?id_product=290&controller=product&id_lang=5
- For a 20V Input voltage -> PWM 45% duty cicle to emulate 6V 
*/
boolean debug = true;
const int EnB = P1_7;
const int In4 = P2_1;  // Use pin with analogWrite support
const int In3 = P2_2;  // Use pin with analogWrite support
const int maxVel = 76;   // Using a 20 V power supply -> 45% PWM = 6V
const int minVel = 38;   // Using a 20 V power supply -> 22% PWM = 3V

void forward(int En, int InX, int InY, int velocity)
{
  velocity = constrain(velocity, minVel, maxVel);
  digitalWrite(En, LOW);
  delay(10);
  analogWrite(InX, velocity);  // PWM 45% Duty Cicle
  analogWrite(InY, 0);
  digitalWrite(En, HIGH);
}

void backward(int En, int InX, int InY, int velocity)
{
  velocity = constrain(velocity, minVel, maxVel);
  digitalWrite(En, LOW);
  delay(10);
  analogWrite(InX, 0);
  analogWrite(InY, velocity);  // PWM 45% Duty Cicle
  digitalWrite(En, HIGH);
}
void fastStop(int En, int InX, int InY)
{
  digitalWrite(En, HIGH);
  digitalWrite(InX, HIGH);
  digitalWrite(InY, HIGH);
}

void freeStop(int En, int InX, int InY)
{
  digitalWrite(En, LOW);
  digitalWrite(InX, LOW);
  digitalWrite(InY, LOW);
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(EnB, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  freeStop(EnB, In3, In4);
  Serial.begin(9600);
}

void loop()
{
  char skipChar = '\n';
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0)
  {
    // look for the information: Forward = 1; Backward = 2
    int movement = Serial.parseInt();
    int velocity = Serial.parseInt();
    if (debug)
    {
      Serial.print("Data Received!");
    }
    if (Serial.read() == '\n')
    {
      if (movement == 1)
      {
        forward(EnB, In3, In4, velocity);
      }
      else if (movement == 2)
      {
        backward(EnB, In3, In4, velocity);
      }
      else
      {
        freeStop(EnB, In3, In4);
        Serial.print("Error! Movement must be: (1) Foward or (2) Backward.");
      }
    }  
  }
}
