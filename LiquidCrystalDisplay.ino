#include <LiquidCrystal.h>

const int rs = 12,
          en = 11, 
          d4 = 5, 
          d5 = 4, 
          d6 = 3, 
          d7 = 2;
String bus1 = "MHS 250---";
String bus2 = "MHS 12--- ";
int time1 = 45;
int time2 = 15;
String display1 = bus1 + " " + String(time1);
String display2 = bus2 + " " + String(time2);

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:
  String display1 = bus1 + " " + String(time1);
  String display2 = bus2 + " " + String(time2);
  lcd.setCursor(0,0);
  lcd.print(display1);
  lcd.setCursor(0,1);
  lcd.print(display2);
  delay(60000);
  time1 = time1 - 1;
  time2 = time2 - 1;
  lcd.clear();

  
}
