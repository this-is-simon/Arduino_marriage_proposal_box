//Marriage Proposal / Treasure Hunt Box
/* I wrote this code with the assistance of software developer Karolin Ecke to propose to my girlfriend. I surprised my girlfriend one day with
a locked 'treasure hunt' box, with an Arduino inside that powered an LCD screen for clues and a button to change to the next clue.
Each clue led her to a different location in our city where one of her friends was waiting with a key or combination to unlock a part of the box.
She said yes!*/

#define BUTTON 7
#define lcdBacklight 8

const int numMessages = 6; // Change depending on number of clues you want
int counter = 0; // Counter starts at 0 and goes up
String messagesA[numMessages] = {"CLUE 1 TOP", "CLUE 2 TOP","CLUE 3 TOP", "CLUE 4 TOP", "CLUE 5 TOP", "CLUE 6 TOP"}; // First row of LCD clues
String messagesB[numMessages] = {"CLUE 1 BOTTOM", "CLUE 2 BOTTOM","CLUE 3 BOTTOM", "CLUE 4 BOTTOM", "CLUE 5 BOTTOM", "CLUE 6 BOTTOM" }; // Second row of LCD clues
bool notPressed = true; // Makes sure only one clue appears each time the button is pressed
#include <LiquidCrystal.h> // include LCD library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // tell LCD which pins to use on Arduino


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
  lcd.begin(16, 2); // LCD is 16 columns, 2 rows
  pinMode(lcdBacklight, OUTPUT);

}

void loop() {
  if (digitalRead(BUTTON) == HIGH )
  {
    if(notPressed) 
    {
      Serial.println(messagesA[counter]);
      lcd.setCursor(0,0); // Set cursor to first row first line
      lcd.print(messagesA[counter]);
      lcd.setCursor(0,1); // Set cursor to first row first line
      digitalWrite(lcdBacklight, HIGH);
      lcd.print(messagesB[counter]);
      delay(12000);
      lcd.clear();
      digitalWrite(lcdBacklight, LOW);
      
      counter = counter + 1; 
      if (counter >= numMessages) // When the counter hits an integer higher than the available number of clues, this code resets the counter (and clues) back to zero
      { 
        counter = 0; 
      }
    } 
    notPressed = false;  // The button has been pressed
  } 
  else if ( digitalRead(BUTTON) == LOW)
  {
    notPressed = true; // The button has been released so the loop can run again
  }  
}
