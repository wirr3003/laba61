#ifndef CONTROL_H
#define CONTROL_H

#define COLOR_MAX 255
#define SIZEWINDOW 1000
#define SIZEBUTTON  64
#define WIDTH 1000
#define HEIGHT 800
#define SIDE 40
#define DOWN 100
#define DEF 10

#define SIZEBUTTONB 170
#define SIZEBUTTONS 80


enum control_values { NONE = -1, SAVE, EXIT, 
                     TURNLEFT, TURNRIGHT, MOVEMENT, SCALE, N_CONTROLS };
enum type_function {NONE_1, MOVEMENT_1, SCALE_1};
  
struct Control{
   int left;
   int top;
   int right;
   int bottom;
};

void create_control(int, int, int, const char*);
int select_control();
void save();

#endif