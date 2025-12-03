int forwardButton = 4;
volatile int speed;
int speedPin = 11;
int joyPin = A0;
int stopButton = 3;
int backButton = 2;
int forward = 8;
int back = 12;
int delayTime = 2000;
volatile int forwardState = LOW;
volatile int stopState = LOW;
volatile int backState = LOW;
//Button states and shi
volatile int buttonStateForward = LOW;
int lastButtonStateForward;
volatile int buttonStateBack = LOW;
int lastButtonStateBack;
volatile int buttonStateStop = LOW;
int lastButtonStateStop;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT_PULLUP);
  for (int i=0; i<5; i++){
    pinMode(i, INPUT);
  }
  for (int i=5; i<14; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int speed = analogRead(joyPin);
  int sped = map(speed, 511, 1023, 0, 255);
  analogWrite(speedPin, sped);
  lastButtonStateForward = buttonStateForward;
  lastButtonStateStop = buttonStateStop;
  lastButtonStateBack = buttonStateBack;
  buttonStateForward = digitalRead(forwardButton);
  buttonStateStop = digitalRead(stopButton);
  buttonStateBack = digitalRead(backButton);
  if (lastButtonStateForward == HIGH && buttonStateForward == LOW) {
    if (forwardState == LOW) {
      forwardState= HIGH;
    }
    else {
      forwardState = LOW;
    }
    digitalWrite(forward, forwardState);
    digitalWrite(back, LOW);
  }
  if (lastButtonStateBack == HIGH && buttonStateBack == LOW) {
    if (backState == LOW) {
      backState= HIGH;
    }
    else {
      backState = LOW;
    }
    digitalWrite(forward, LOW);
    digitalWrite(back, backState);
  }
  if (lastButtonStateStop == HIGH && buttonStateStop == LOW) {
    digitalWrite(forward, LOW);
    digitalWrite(back, LOW);
  }

}
