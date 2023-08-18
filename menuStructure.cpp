#include "menuStructure.h"

String getMenuOption(int menuPos) {
  // Map menuPos to a value between 0 and 4
  int mappedPos = menuPos % 5;
  if (mappedPos < 0) {
    mappedPos += 5;
  }

  // Determine the menu option based on the mapped position
  String menuOption;
  switch (mappedPos) {
    case 0:
      menuOption = "Start";
      break;
    case 1:
      menuOption = "Shiplights";
      break;
    case 2:
      menuOption = "Usage";
      break;
    case 3:
      menuOption = "Battery";
      break;
    case 4:
      menuOption = "Usage Log";
      break;
    default:
      menuOption = "Start";
      break;
  }

  return menuOption;
}
