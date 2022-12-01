#include <cmath>
#include "graphics.h"
#include <cstdlib>
#include "task.hpp"
#include "control.h"
#include "ctime"
#include <iostream>
#include <fstream>

using namespace std;

const double PI = acos(0.0)*2.0;

Figure::Figure()
{
   ifstream file;
   file.open("info_for_figure.txt");
   file >> count_vertex;
   
  points_fig = new Point[count_vertex];
   
   for (int i = 0; i < count_vertex; i++)
   {
      file >> points_fig[i].x >> points_fig[i].y;
      
      printf("(%.2lf;%.2lf)-", points_fig[i].x, points_fig[i].y);
   }
   center();
   draw();
}

void Figure::center()
{
   for(int i=0; i<count_vertex; i++)
   {
      center_1.x += points_fig[i].x;
      center_1.y += points_fig[i].y;
   }
   center_1.x /= count_vertex;
   center_1.y /= count_vertex;
}

void Figure::spin(double angle)
{
   angle_fig += angle*(PI/180.0);
   draw();
}

void Figure::movement(double x, double y)
{
   center_fig.x += x;
   center_fig.y += y;
   draw();
}

void Figure::scale(double factor)
{
   factor_fig *= factor;
   draw();
}

void Figure::draw()
{
   Point points[count_vertex];
   int point_draw[2*count_vertex];
   for (int i = 0; i < count_vertex; i++)
   {
      points[i] = points_fig[i];
      
      points[i].x += center_fig.x;
      points[i].y += center_fig.y;
      center();
      
      points[i].x = center_1.x+(-center_1.x+points_fig[i].x)*cos(angle_fig)+(center_1.y-points_fig[i].y)*sin(angle_fig);
      points[i].y = center_1.y+(-center_1.x+points_fig[i].x)*sin(angle_fig)+(-center_1.y+points_fig[i].y)*cos(angle_fig);

      points[i].x *= factor_fig;
      points[i].y *= factor_fig;

      points[i].x = points[i].x + WIDTH/2.0;
      points[i].y = HEIGHT/2.0 - points[i].y;
   }
   
   for (int i = 0; i < 2*count_vertex; i+=2)
   {
      printf("(%.2lf;%.2lf)-", points[i/2].x, points[i/2].y);
      point_draw[i] =points[i/2].x;
      point_draw[i+1] = points[i/2].y;
   }
   cout << endl;
   
   setfillstyle(SOLID_FILL, BLACK);
   fillpoly(count_vertex, point_draw);

   setcolor(RED);
   setfillstyle(SOLID_FILL, RED);

}

void save()
{
   int w, h;
   IMAGE *output;
   
   w = getmaxx() + 1;
   h = getmaxy() + 1;
   output = createimage(w, h);
   
   getimage(0, 0, w - 1, h - 1, output);
   saveBMP("output1.png", output);
   freeimage(output);
}

