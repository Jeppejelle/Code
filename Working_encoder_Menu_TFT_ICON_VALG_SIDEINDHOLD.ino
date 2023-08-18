#include <Arduino.h>
#include "EncoderHandler.h"
#include "menuStructure.h"
#include "DisplayPrint.h"
#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>
#include "menuPrint.h"

MCUFRIEND_kbv tft;

const int encoderPinA = 2;
const int encoderPinB = 3;
int menuPos = 0;

bool menuUpdate = false;
String previousMenuOption = "";

void setup() {
  String menuOption = getMenuOption(menuPos);
  Serial.begin(9600);
  Serial.print("Startup Menu Option: ");
  Serial.println(menuOption);

  tft.reset();
  uint16_t g_identifier = tft.readID();
  tft.begin(g_identifier);
  tft.setRotation(1);
  g_identifier = tft.readID();
  tft.begin(0x9488);
  tft.fillScreen(BLACK);
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  digitalWrite(encoderPinA, HIGH);
  digitalWrite(encoderPinB, HIGH);
  
  attachInterrupt(digitalPinToInterrupt(encoderPinA), []{ handleInterrupt(menuPos); }, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), []{ handleInterrupt(menuPos); }, CHANGE);



  DisplayPrint::initialize();
  MenuPrint::displayMenu(tft, menuOption.c_str());
  
}

void loop() {
    if (menuUpdate) {
        String menuOption = getMenuOption(menuPos);
        DisplayPrint::updateDisplay(menuOption);

        MenuPrint::displayMenu(tft, menuOption.c_str());


        previousMenuOption = menuOption;
        menuUpdate = false;
    }

    // Your other loop logic goes here
}
