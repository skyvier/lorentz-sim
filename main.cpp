#include "particle_manager.h"

int main() {
   std::cout << "TESTS: " << std::endl;

   particle_manager manager(0.0000001);

   vector3 location1(0,0,0); vector3 velocity(1000,0,0); vector3 location2(0.01,0.01,0);
   vector3 location3(0,-0.01,0); vector3 location4(0.01,0,0);
   particle electron1(location1, velocity, constant::electron_charge, constant::electron_mass);
   particle electron2(location2, velocity, constant::electron_charge, constant::electron_mass);
   particle electron3(location3, velocity, constant::electron_charge, constant::electron_mass);
   particle electron4(location4, velocity, constant::electron_charge, constant::electron_mass);
   particle proton(vector3(0.5,0,0), velocity, -100*constant::electron_charge, constant::proton_mass);

   manager.add(electron1);
   manager.add(electron2);
   manager.add(electron3);
   manager.add(electron4);
   manager.add(proton);

   int tic = 0;
   while(manager.get_time() < 0.3) {
      tic++;
      manager.update_particles();
      if(tic % 100 == 0) 
         manager.print_data();
   }

   return 0;
}
