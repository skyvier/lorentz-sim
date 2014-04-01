#include "vector3.h"

vector3::vector3(double x, double y, double z) {
   _x = x; _y = y; _z = z;
}

vector3::vector3() {
   _x = 0; _y = 0; _z = 0;
}

vector3 vector3::operator+(vector3 v) {
   vector3 temp = vector3(_x+v.x(), _y+v.y(), _z+v.z());
   return temp;  
} 

vector3 vector3::operator-(vector3 v) {
   v.complement();
   return *this+v; 
}

vector3 vector3::operator*(double a) {
   vector3 temp = vector3(_x*a,_y*a,_z*a);
   return temp;
} 

double vector3::scalar_product(vector3 v1, vector3 v2) {
   return v1.x()*v2.x()+v1.y()*v2.y()+v1.z()*v2.z();
}

vector3 vector3::cross_product(vector3 v1, vector3 v2) {
   double nx, ny, nz;
   nx = v1.y()*v2.z()-v1.z()*v2.y();
   ny = v1.z()*v2.x()-v1.x()*v2.z();
   nz = v1.x()*v2.y()-v1.y()*v2.x();
   vector3 temp = vector3(nx, ny, nz);   
   return temp;
}


