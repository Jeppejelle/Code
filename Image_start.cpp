// Image_start.cpp
#include "Image_start.h"
#include "DisplayPrint.h"

// Define battery-related variables
int batteryPercentage = 75; // Example battery percentage

void Image_start::display() {
    MCUFRIEND_kbv &tft = DisplayPrint::tft;

    tft.fillScreen(BLACK);

    tft.setTextColor(WHITE);
    tft.setTextSize(6);

    int textWidth = 4 * 5 * 6;
    int x = (tft.width() - textWidth) / 2;
    int y = (tft.height() - 3 * 8) / 2;

    tft.setCursor(x, y);
    tft.println("START");

    // Display battery information
    tft.setTextSize(2);
    tft.setCursor(10, tft.height() - 30); // Adjust the coordinates as needed
    tft.print("Battery: ");
    tft.print(batteryPercentage);
    tft.print("%");
}
