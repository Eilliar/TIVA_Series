/*
Hello World!

Author: Bruno Godoi Eilliar
Date: May 30, 2015
*/

// Global variables declaration
int SW1_state = 0;

// Hardware Configuration
void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(PUSH1, INPUT_PULLUP);  
}

// Main loop
void loop()
{
  SW1_state = digitalRead(PUSH1);
  if (SW1_state == HIGH){
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }
  else {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
  } 
}
