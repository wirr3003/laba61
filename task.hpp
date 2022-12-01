#ifndef TASK_H 
#define TASK_H

struct Point
{
   double x = 10;
   double y = 10;
};

class Figure
{
   int count_vertex;
   Point *points_fig;
   Point center_1;
   Point center_fig;
   double angle_fig = 0;
   double factor_fig = 1;

public:
   Figure();
   ~Figure() = default;
   void center();
   void movement(double x, double y);
   void spin(double angle);
   void scale(double factor);
   void draw();
};

void save();

#endif