
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int display = 1;
int display2 = 1;
int increase = 6;
int decrease = 7;
int nextNumber = 8;
int add = 9;
int startOver = 10;
int increaseStatus;
int decreaseStatus;
int nextNumberStatus;
int addStatus;
int startOverStatus;
int result;
int doNext = 0;
int readyToStart = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Enter first num");
}

void loop() {
  increaseStatus = digitalRead(increase);
  decreaseStatus = digitalRead(decrease);
  nextNumberStatus = digitalRead(nextNumber);
    if (nextNumberStatus == 1) {
      lcd.clear();
      lcd.print("Enter second num");
      doNext = 1;
    }
  if (doNext == 1) {
      addStatus = digitalRead(add);
      startOverStatus = digitalRead(startOver);
      if (increaseStatus == 1) {
        display2++;
        lcd.clear();
        lcd.print(display2);
        delay(300);
      }
      if (decreaseStatus == 1) {
        display2--;
        lcd.clear();
        lcd.print(display2);
        delay(300);
      }
      if (addStatus == 1) {
        lcd.clear();
        result = display + display2;
        readyToStart = 1;
        lcd.print(display);
        if (display2 < 0) {
          lcd.print("-");
          int actualDisplay2 = abs(display2);
          lcd.print(actualDisplay2);
        }
        else{
          lcd.print("+");
          lcd.print(display2);
        }
        lcd.print(" ");
        lcd.print("RESULT: ");
        lcd.print(result);
        delay(500);
      }
      if (readyToStart == 1) {
        if (startOverStatus == 1) {
          lcd.clear();
          lcd.print("resetting...");
          delay(300);
          lcd.clear();
          lcd.print("enter first num");
          readyToStart = 0;
          doNext = 0;
          display = 1;
          display2 = 1;
          delay(500);
        }
      }
  }
  else{
    if (increaseStatus == 1) {
      display++;
      lcd.clear();
      lcd.print(display);
      delay(300);
    }
     if (decreaseStatus == 1) {
      display--;
      lcd.clear();
      lcd.print(display);
      delay(300);
    }
  }
}
