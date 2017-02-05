default: rover_sim.o state_rover.o rover_sampler.o rover_camera.o rover_nav_unit.o rover_grid_map.o
	g++ -o state_reflex_rover rover_sim.o state_rover.o rover_sampler.o rover_camera.o rover_nav_unit.o rover_grid_map.o

rover_sim.o: rover_sim.cc 
	g++ -c rover_sim.cc -std=c++11

state_rover.o: state_rover.cc
	g++ -c state_rover.cc -std=c++11

rover_sampler.o: rover_sampler.cc
	g++ -c rover_sampler.cc -std=c++11

rover_camera.o: rover_camera.cc
	g++ -c rover_camera.cc -std=c++11

rover_nav_unit.o: rover_nav_unit.cc
	g++ -c rover_nav_unit.cc -std=c++11

rover_grid_map.o: rover_grid_map.cc
	g++ -c rover_grid_map.cc -std=c++11

clean: 
	rm -f *.o
	rm state_reflex_rover
