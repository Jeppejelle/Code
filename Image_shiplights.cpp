// Image_start.cpp
#include "Image_shiplights.h"
#include "DisplayPrint.h"

void Image_shiplights::display() {
    MCUFRIEND_kbv &tft = DisplayPrint::tft;

    tft.fillScreen(BLACK);

    tft.setTextColor(WHITE);
    tft.setTextSize(3);

    int textWidth = 4 * 5 * 6;
    int x = (tft.width() - textWidth) / 2;
    int y = (tft.height() - 3 * 8) / 2;

    tft.setCursor(x, y);
    tft.println("Shiplights");
}
