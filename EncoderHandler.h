#ifndef ENCODER_HANDLER_H
#define ENCODER_HANDLER_H

#include <Arduino.h>

extern bool menuUpdate; // Declare the menuUpdate flag globally

// Function declaration
void handleInterrupt(int& menuPos);

#endif
