int buttonForward = 4;
int buttonBack = 2;
int led1 = 10;
int led2 = 9;
int led3 = 6;
int led4 = 5;
volatile int buttonForwardState;
volatile int buttonBackState;
int lastButtonForwardState;
int lastButtonBackState;
int forward = 13;
int forwardState = LOW;
int back = 12;
int control = A0;
int speed;
int speedControl;
int power = 11;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 1; i < 5; i++){
    pinMode(i, INPUT);
  }
  for (int i = 5; i < 14; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(speed, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  speed = analogRead(control);
  speedControl = map(speed, 511, 1023, 0, 255);
  analogWrite(power, speedControl);
  
  if (speedControl < 64){
    int led1Power = map(speedControl, 0, 64, 0, 255);
    analogWrite(led1, led1Power);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    
  }
  if (speedControl > 64 && speedControl < 128) {
    int led2Power = map(speedControl, 64, 128, 0, 255);
    analogWrite(led1, 255);
    analogWrite(led2, led2Power);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
  if (speedControl > 128 && speedControl < 192) {
    int led3Power = map(speedControl, 128, 192, 0, 255);
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, led3Power);
    digitalWrite(led4, 0);
  }
    if (speedControl > 192 && speedControl < 255) {
    int led4Power = map(speedControl, 192, 255, 0, 255);
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    analogWrite(led4, led4Power);
  }
  delay(100);
  Serial.println(speedControl);
  lastButtonForwardState = buttonForwardState;
  lastButtonBackState = buttonBackState;
  buttonForwardState = digitalRead(buttonForward);
  buttonBackState = digitalRead(buttonBack);
  if (lastButtonForwardState == HIGH && buttonForwardState == LOW){
    if (forwardState == LOW){
      forwardState = HIGH;
    }
    else{
      forwardState = LOW;
    }
    digitalWrite(forward, forwardState);
    digitalWrite(back, LOW);
  }
  if (lastButtonBackState == HIGH && buttonBackState == LOW){
    if (forwardState == LOW){
      forwardState = HIGH;
    }
    else{
      forwardState = LOW;
    }
    digitalWrite(forward, LOW);
    digitalWrite(back, forwardState);

  }

}
