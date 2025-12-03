int button = 2;
int power = 3;
int red = 6;
int blue = 5;
int yellow = 10;
int green = 11;
int ledState = LOW;
int buttonState;
int lastButtonState;
int yPin = A1;
int xPin = A0;


void setup() {
  // put your setup code here, to run once:
  //pinMode(button, INPUT);
  for (i=3; i<13; i++) {
    pinMode(i, OUTPUT);
  }
  volatile int buttonState = digitalRead(button);
  //pinMode(yPin, INPUT);
  //pinMode(xPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(power, HIGH);
  lastButtonState = buttonState;
  buttonState = digitalRead(button);
 
  if (lastButtonState == HIGH && buttonState == LOW) {
    if (ledState == HIGH){
      ledState = LOW;
      digitalWrite(blue, ledState);
      digitalWrite(yellow, ledState);
      digitalWrite(red, ledState);
      digitalWrite(green, ledState);
    }
    else {
      ledState = HIGH;
      while (ledState == HIGH) {
        digitalWrite(blue, HIGH);
        delay(100);
        digitalWrite(blue, LOW);
        digitalWrite(yellow, HIGH);
        delay(100);
        digitalWrite(yellow, LOW);
        digitalWrite(green, HIGH);
        delay(100);
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
        delay(100);
        digitalWrite(red, LOW);
        delay(500);
        digitalWrite(red, HIGH);
        digitalWrite(blue, HIGH);
        digitalWrite(green, HIGH);
        digitalWrite(yellow, HIGH);
        delay(1000);
        digitalWrite(red, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(green, LOW);
        digitalWrite(yellow, LOW);
        delay(200);

      }

    }
  }
}
