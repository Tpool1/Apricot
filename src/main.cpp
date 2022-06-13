/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\tp985946                                         */
/*    Created:      Wed May 11 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 3, 4, 5   
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "math.h"
#include "GUI.h"

using namespace vex;

competition Competition;

// coordinate of robot; initially set to (0,0)
float coor[2] = {0, 0};

// coordinate of goal
int goal_position[2] = {2, 2};

double v(float x) {
  return Drivetrain.velocity(rpm);
}

// input theta in degrees; d in inches
void log_position(float theta, float d) {
  float x = sin(theta)*d;
  float y = cos(theta)*d;
  coor[0] = coor[0] + x;
  coor[1] = coor[1] + y;
}

double trapezoidalRule (int ti, int tf, int sub_intervals, double (*f)(float)) {
  double h = abs(tf-ti)/sub_intervals;
  double ifx = 0;
  ifx = ifx + f(ti) + f(tf);
  for(double i=ti+h; i<tf;){
    ifx=ifx+(2*f(i));
    i = i + h;
  }
  ifx = ifx*h/2;
  return ifx;
}

/*
dx - Distance projectile is to be thrown
t - time projectile takes to reach desired x coordinate
theta - angle at which projectile is to be thrown
returns the acceleration necessary
*/
float dv(float dx, float t, double theta) {
  float change_v = dx/t* cos(theta);
  return change_v;
}

/*
x0 - initial x coordinate (most of the time 0)
ti - inital time (most of the time 0)
tf - final time 
returns x at tf with velocity v
*/
float xt(float x0, int ti, int tf) {
  // use 100 subintervals
  float result = x0 + trapezoidalRule(ti, tf, 100, v);
  return result;
}

void autonomous(void) {
  Drivetrain.driveFor(forward, 12, inches);
  log_position(0, 12);
}

void usercontrol(void) {
  
}

float get_distance_from_goal(void) {
  // use distance formula to find d between goal position and robot
  float d = sqrt(pow((goal_position[0]-coor[0]), 2)+pow((goal_position[1]-coor[1]), 2));
  return d;
}

void face_goal(void) {
  double desired_bot_or = atan(coor[0]-goal_position[0] / coor[1]-goal_position[1]);

  Drivetrain.turnToHeading(180-desired_bot_or, degrees);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // draw GUI
  draw();

  Drivetrain.setDriveVelocity(70, percent);
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  // prevent main from exiting with an infinite loop
  while (true) {
    wait(100, msec);
  }
}
