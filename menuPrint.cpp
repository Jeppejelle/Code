#include "menuPrint.h"
#include "menuImage.h"
#include <avr/pgmspace.h>
#include <MCUFRIEND_kbv.h>

static int lastSelectedIndex = -1; // Initialize to an invalid value

void MenuPrint::displayMenu(MCUFRIEND_kbv &tft, const char *selectedOption) {
    const uint16_t iconWidth = 64;
    const uint16_t iconHeight = 64;
    const int screenHeight = tft.height();

    const unsigned char *const menuIcons[] PROGMEM = {
        icon_start,
        icon_shiplights,
        icon_usage,
        icon_battery,
        icon_usagelog
    };

    const char *const menuItems[] = {
        "Start",
        "Shiplights",
        "Usage",
        "Battery",
        "Usage Log"
    };

    for (int i = 0; i < sizeof(menuIcons) / sizeof(menuIcons[0]); ++i) {
        int x = i * iconWidth;
        int y = screenHeight - iconHeight; // Y-coordinate at the bottom of the screen

        bool isSelected = (strcmp(selectedOption, menuItems[i]) == 0);

        if (isSelected) {
            // Clear the previously selected icon
            int lastX = lastSelectedIndex * iconWidth;
            tft.fillRect(lastX, y, iconWidth, iconHeight, BLACK);
            tft.drawBitmap(lastX, y, menuIcons[lastSelectedIndex], iconWidth, iconHeight, WHITE);

            // Highlight the selected icon
            tft.fillRect(x, y, iconWidth, iconHeight, WHITE); // Inverted color for highlighted icon
            tft.drawBitmap(x, y, menuIcons[i], iconWidth, iconHeight, BLACK);

            lastSelectedIndex = i; // Update the last selected index
        } else {
            tft.drawBitmap(x, y, menuIcons[i], iconWidth, iconHeight, WHITE);
        }
    }
}
