
#define BLACK   0x0000
#define WHITE   0xFFFF


#ifndef MENUPRINT_H
#define MENUPRINT_H

#include <MCUFRIEND_kbv.h>

class MenuPrint {
public:
    static void refreshLastSelected(MCUFRIEND_kbv &tft);
    static void displayMenu(MCUFRIEND_kbv &tft, const char *selectedOption);

private:
    static const unsigned char *const menuIcons[] PROGMEM;
};

#endif // MENUPRINT_H
