/*
Project: Control DC Motors using MotMama v.2 (L298N Driver)

Author:Bruno Godoi Eilliar
Date: September 26, 2015.

Notes:
- http://energia.nu/Tutorial_PWM.html
- Motors: http://www.botnroll.com/index.php?id_product=290&controller=product&id_lang=5
- For a 20V Input voltage -> PWM 45% duty cicle
*/

const int EnB = P1_7;
const int In4 = P2_1;
const int In3 = P2_2;

void forward(int En, int InX, int InY)
{
  digitalWrite(En, LOW);
  analogWrite(InX, 76);  // PWM 45% Duty Cicle
  analogWrite(InY, 0);
  digitalWrite(En, HIGH);
}

void backward(int En, int InX, int InY)
{
  digitalWrite(En, LOW);
  analogWrite(InX, 0);
  analogWrite(InY, 76);  // PWM 45% Duty Cicle
  digitalWrite(En, HIGH);
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(EnB, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  digitalWrite(EnB, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
  forward(EnB, In3, In4);
  delay(5000);
  digitalWrite(EnB, LOW);
  delay(100);
  backward(EnB, In3, In4);
  delay(5000);
  digitalWrite(EnB, LOW);
  delay(100);
}
