#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

#include "particle.h"
#include <vector>

class particle_manager {
   private:
    std::vector<particle> particles; 
    double interval;
    double time;
   public:
    particle_manager(double time_interval) { interval = time_interval; time = 0;}

    void add(particle p) { particles.push_back(p); }

    void update_particles();
    void print_data();

    double get_time() { return time; }
};

#endif
