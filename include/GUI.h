#include "vex.h"

using namespace vex;

int screenW = 480;
int screenH = 240;

int buttonSize = 100;

void draw(void) {

  Brain.Screen.drawRectangle(0, 0, screenW, screenH, vex::orange);
  Brain.Screen.printAt(screenW/4, screenH/2, "Welcome to Apricot OS!");

  wait(5, sec);

  Brain.Screen.clearScreen();

  Brain.Screen.drawRectangle(screenW*(7/8), screenH/2, buttonSize, buttonSize, vex::purple);
  Brain.Screen.printAt(screenW*(7/8), screenH/2, "Left Auton.");

  Brain.Screen.drawRectangle(screenW/3, screenH/2, buttonSize, buttonSize, vex::purple);
  Brain.Screen.printAt(screenW/3, screenH/2, "Right Auton.");
}

void run(void) {
  while (true) {
    if (Brain.Screen.xPosition() > screenW*(7/8)) {
      if (Brain.Screen.xPosition() < screenW*(7/8)+buttonSize) {
        if (Brain.Screen.yPosition() > screenH/2) {
          if (Brain.Screen.yPosition() < screenH/2+buttonSize) {
            bool leftAuton = true;
          }
        }
      }
    }
    if (Brain.Screen.xPosition() > screenW/3) {
      if (Brain.Screen.xPosition() < screenW/3+buttonSize) {
        if (Brain.Screen.yPosition() > screenH/2) {
          if (Brain.Screen.yPosition() < screenH/2+buttonSize) {
            bool leftAuton = false;
          }
        }
      }
    }
    wait(100, msec);
  }
}
