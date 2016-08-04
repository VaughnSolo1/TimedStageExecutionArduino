#define FIRST_STAGE 8280000
#define SECOND_STAGE "millisions for time limit"
#define THIRD_STAGE "millissecond sfor time limit"

int led1 = 3;           // LED connected to digital pin 3
int led2 = 5;           // LED connected to digital pin 5
int led3 = 6;           // LED connected to digital pin 6
int led4 = 9;           // LED connected to digital pin 9
int led5 = 10;          // LED connected to digital pin 10


void setup() 
{
  pinMode(led1, OUTPUT);    //setting digital pins as outputs
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  static unsigned long pastTime = millis();
  while ((millis() - pastTime) <= FIRST_STAGE) {
    // This is where first stage occurs
    digitalWrite(led1, HIGH);  // Putting output pins to their initial states, off
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH); 
  }
}

void loop() {
  static unsigned long pastTimeInLoop = millis();

  if ((millis() - pastTimeInLoop) >= SECOND_STAGE) {                         
    // This is where third stage occurs
    digitalWrite(led1, HIGH);  // Putting output pins to their initial states, off
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH); 
  } else if ((millis() - pastTimeInLoop) < SECOND_STAGE) {
    // This is where second stage occurs
    digitalWrite(led1, LOW);  // Putting output pins to their initial states, off
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  } 

  if ((millis() - pastTimeInLoop) >= (SECOND_STAGE + THIRD_STAGE)) {                         
    // This is where we reset our timer to go back to second stage
    pastTimeInLoop = millis();
  }
}
