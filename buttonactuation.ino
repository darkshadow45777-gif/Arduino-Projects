int buttonPin = 2;
int ledRed = 11;
int ledBlue = 13;



//void buttonInterrupt() {
  
  //int buttonState = digitalRead(buttonPin);
    //digitalWrite(ledRed, buttonState);

//}

void buttonInterrupt() {
  volatile int buttonState = digitalRead(buttonPin); 

  if (buttonState == HIGH) {
    digitalWrite(ledRed, LOW);
  }

  if (buttonState == LOW) {
    digitalWrite(ledRed, HIGH);

  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE);

}




void loop() {
  
  // put your main code here, to run repeatedly:

  
  digitalWrite(ledBlue, HIGH);
  delay(1000);
  digitalWrite(ledBlue, LOW);
  delay(1000);

}