#include "particle_manager.h"

void particle_manager::update_particles() {
   vector3 electric, magnetic;
   for(int i = 0; i < particles.size(); i++) {
      electric = vector3(0,0,0);
      magnetic = vector3(0,0,0);
      
      for(int l = 0; l < particles.size(); l++) {
         if(l != i) {
            electric = electric + particles.at(l).electric_field(particles.at(i).get_location());
            magnetic = magnetic + particles.at(l).magnetic_field(particles.at(i).get_location());
         }
      }
      
      particles.at(i).update(electric,magnetic,interval); 
   }

   time += interval;
}

void particle_manager::print_data() {
   for(int i = 0; i < particles.size(); i++) {
      particles.at(i).get_location().bareprint();
   }
}
