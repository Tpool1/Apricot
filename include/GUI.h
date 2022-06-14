#include "vex.h"

using namespace vex;

int screenW = 480;
int screenH = 240;

int borderSize = 10;

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

  Brain.Screen.drawRectangle(screenW/2, screenH/2, buttonSize, buttonSize, vex::purple);
  Brain.Screen.printAt(screenW/2, screenH/2, "Driver Control");
}

std::string getSelection(void) {
  std::string selection = "none";
  bool leftAuton;
  while (selection == "none") {
    if (Brain.Screen.xPosition() > screenW*(7/8)) {
      if (Brain.Screen.xPosition() < screenW*(7/8)+buttonSize) {
        if (Brain.Screen.yPosition() > screenH/2) {
          if (Brain.Screen.yPosition() < screenH/2+buttonSize) {
            leftAuton = true;
            selection =  "left";
          }
        }
      }
    }
    if (Brain.Screen.xPosition() > screenW/3) {
      if (Brain.Screen.xPosition() < screenW/3+buttonSize) {
        if (Brain.Screen.yPosition() > screenH/2) {
          if (Brain.Screen.yPosition() < screenH/2+buttonSize) {
            leftAuton = false;
            selection = "right";
          }
        }
      }
    }
    // initially set driver to false
    bool driver = false;
    if (Brain.Screen.xPosition() > screenW/2) {
      if (Brain.Screen.xPosition() < screenW/2+buttonSize) {
        if (Brain.Screen.yPosition() > screenH/2) {
          if (Brain.Screen.yPosition() < screenH/2+buttonSize) {
            driver = true;
            selection = "driver";
          }
        }
      }
    }
  }
  return selection;
}

void drawAnalytics(float coor[2]) {

  Brain.Screen.clearScreen();

  // draw sqare outline of map
  int mapH = screenH-borderSize;
  int mapW = screenW-mapH;
  Brain.Screen.drawRectangle(borderSize, borderSize, mapW, mapH, vex::white);

  // draw game features onto map
  // draw center diagonal line
  Brain.Screen.drawLine(0, mapH, mapW, 0);

  // draw "goal boxes"
  Brain.Screen.drawRectangle(borderSize, mapH/3+borderSize, mapW/3, mapH/3);
  Brain.Screen.drawRectangle(mapW*(2/3)+borderSize, mapH+borderSize, mapW/3, mapH/3);

  // draw circle with center at robot position and radius 10
  Brain.Screen.drawCircle(coor[0], coor[1], 10);
}
