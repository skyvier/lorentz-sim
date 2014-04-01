#include "particle.h"

vector3 particle::electric_field(vector3 r) {
   vector3 distance = r-location;
   double coefficient = constant::coulomb_constant*(charge/pow(distance.norm(),2));
   vector3 direction = distance*(1/distance.norm());
   return direction*coefficient; 
}

vector3 particle::magnetic_field(vector3 r) {
   vector3 distance = r-location;
   double coefficient = constant::magnetic_constant*(1/pow(distance.norm(),2));
   return vector3::cross_product(velocity*charge, distance*(1/distance.norm()))*coefficient;
}

void particle::update(vector3 electric, vector3 magnetic, double interval) {
   // Lorentz-force:
   vector3 force = electric*charge+vector3::cross_product(velocity*charge, magnetic);
   acceleration = force*(1/mass);
   
   location = location + velocity*interval + acceleration*(0.5*pow(interval,2)); 
   velocity = velocity + acceleration*interval;
}
