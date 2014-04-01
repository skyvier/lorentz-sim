function plot_particles = plot_particles()
   S = dlmread("output.txt", " ");
   x = S(:,1);
   y = S(:,2);
   z = S(:,3);
   plot(x,y,'.');
end
