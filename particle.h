#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector3.h"

namespace constant {
   const double pi = 3.141592;
   const double vacuum_p = 8.85419e-12;
   const double coulomb_constant = 8.98755e9;
   const double magnetic_constant = 1e-7;
   const double electron_mass = 9.1093897e-31;
   const double electron_charge = -1.6021773e-19;
   const double proton_mass = 1.6726231e-27;
}

class particle {
   private:
    vector3 location, velocity, acceleration;
    double charge;
    double mass;

   public:
    particle(vector3 location, vector3 velocity, double charge, double mass) {
       this->location = location; this->velocity = velocity;
       this->acceleration = vector3(0,0,0);

       this->charge = charge;
       this->mass = mass;
    }

    particle(double charge, double mass) { this->charge = charge; this->mass = mass; }

    vector3 get_location() { return location; }

    /* Coulomb's law */
    vector3 electric_field(vector3 r);

    /* Biot-Savart law */
    vector3 magnetic_field(vector3 r);

    void update(vector3 electric, vector3 magnetic, double interval);
};

#endif
