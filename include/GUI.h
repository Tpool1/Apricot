#include "vex.h"

using namespace vex;

void draw(void) {
  Brain.Screen.drawRectangle(75, 75, 100, 100, vex::blue);
  Brain.Screen.printAt(75, 115, "Left Auton.");

  Brain.Screen.drawRectangle(200, 75, 100, 100, vex::blue);
  Brain.Screen.printAt(200, 115, "Right Auton.");
}

void run(void) {
  while (true) {
    if (Brain.Screen.xPosition() > 75) {
      if (Brain.Screen.xPosition() < 175) {
        if (Brain.Screen.yPosition() > 75) {
          if (Brain.Screen.yPosition() < 175) {
            bool leftAuton = true;
          }
        }
      }
    }
    if (Brain.Screen.xPosition() > 200) {
      if (Brain.Screen.xPosition() < 300) {
        if (Brain.Screen.yPosition() > 75) {
          if (Brain.Screen.yPosition() < 175) {
            bool leftAuton = false;
          }
        }
      }
    }
    wait(100, msec);
  }
}
