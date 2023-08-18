// DisplayPrint.h
#ifndef DISPLAY_PRINT_H
#define DISPLAY_PRINT_H

#include <MCUFRIEND_kbv.h>

class DisplayPrint {
public:
    static MCUFRIEND_kbv tft;

    static void initialize();
    static void updateDisplay(String menuOption);
};

// Define color constants
#define BLACK   0x0000
#define WHITE   0xFFFF

#endif
