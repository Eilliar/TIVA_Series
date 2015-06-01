
volatile int state = HIGH;
volatile int flag = HIGH;
int count = 0;

void setup()
{
  // put your setup code here, to run once:
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, state);
  
  pinMode(PUSH2, INPUT_PULLUP);
  attachInterrupt(PUSH2, blink, FALLING);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(GREEN_LED, state);
  if (flag){
    count++;
    flag = LOW;
  }
}

void blink(){
  state = !state;
  flag = HIGH;
}
