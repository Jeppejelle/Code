#include "EncoderHandler.h"
#include <Arduino.h> // Include Arduino library for pin definitions

void handleInterrupt(int& menuPos) {
  // Read the state of the pins
  const int encoderPinA = 2;
  const int encoderPinB = 3;
  static bool pinBHitsZero;
  static bool pinAHitsZero;

  int stateA = digitalRead(encoderPinA);
  int stateB = digitalRead(encoderPinB);
  static int plusMinus = 0;
  static bool collecteddata = false;

  if (stateA == HIGH && stateB == LOW && !collecteddata) {
    collecteddata = true;
    plusMinus = -1;
    //Serial.println("LEFT");
  }

  if (stateA == LOW && stateB == HIGH && !collecteddata) {
    collecteddata = true;
    plusMinus = 1;
    //Serial.println("RIGHT");
  }
  
  // Check if Pin A or Pin B hits 0
  if (!pinAHitsZero && stateA == LOW) {
    pinAHitsZero = true;
  }
  if (!pinBHitsZero && stateB == LOW) {
    pinBHitsZero = true;
  }
  
  // Check if both pins have hit 0 and both are back to 1
  if (pinAHitsZero && pinBHitsZero && stateA == HIGH && stateB == HIGH) {
    // Increment or decrement menuPos based on plusMinus value
    if (plusMinus == -1){
      menuPos--;
    }
    if (plusMinus == 1){
      menuPos++;
    }

    //Serial.print("Menu Pos: ");
    //Serial.println(menuPos);
    menuUpdate = true;

    // Reset the hit-zero flags and other variables
    pinAHitsZero = false;
    pinBHitsZero = false;
    collecteddata = false;
    plusMinus = 0;
  }
}
