#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

class vector3 {
  private:
   double _x,_y,_z;
  public: 
   /* Constructors */
   vector3(double x, double y, double z);
   vector3();

   /* Accessors */
   double x() { return _x; }
   double y() { return _y; }
   double z() { return _z; }

   double norm() { return sqrt(pow(_x,2)+pow(_y,2)+pow(_x,2)); }

   /* Operators */
   vector3 operator+(vector3 v);
   vector3 operator-(vector3 v);
   vector3 operator*(double a);
   
   /* Functions */
   static double scalar_product(vector3 v1, vector3 v2);
   static vector3 cross_product(vector3 v1, vector3 v2);

   void complement() { _x = -_x; _y = -_y; _z = -_z; }

   void print() { std::cout << "(" << _x << "," << _y << "," << _z << ")" << std::endl; }
   void bareprint() { std::cout << _x << " " << _y << " " << _z << std::endl; }
};

#endif
