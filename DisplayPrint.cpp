// DisplayPrint.cpp
#include "DisplayPrint.h"
#include "Image_start.h"
#include "Image_shiplights.h" // Include other image headers
#include "Image_usage.h"
#include "Image_battery.h"
#include "Image_usagelog.h"
#include "menuPrint.h"

MCUFRIEND_kbv DisplayPrint::tft;

void DisplayPrint::initialize() {
    tft.reset();
    uint16_t g_identifier = tft.readID();
    tft.begin(g_identifier); // Initialize the display
    tft.setRotation(0); // Set rotation to portrait
    
    // Display the menu at the bottom of the screen
    
}

void DisplayPrint::updateDisplay(String menuOption) {
   // tft.fillScreen(BLACK);
if (menuOption == "Start") {
        Image_start::display();
        tft.println("Displaying Image_start");
    } else if (menuOption == "Shiplights") {
       Image_shiplights::display();
        tft.println("Displaying Image_shiplights");
    } else if (menuOption == "Usage") {
        Image_usage::display();
       tft.println("Displaying Image_usage");
    } else if (menuOption == "Battery") {
       Image_battery::display();
        tft.println("Displaying Image_battery");
    } else if (menuOption == "Usage Log") {
        Image_usagelog::display();
        tft.println("Displaying Image_usagelog");
    }
    //Serial.println("Menu Option DISPLAYPRINT: " + menuOption);

    
    // Add more conditions for other menu options and corresponding screens here
}
