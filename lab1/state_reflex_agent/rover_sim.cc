#include "state_rover.h"
#include "rover_grid_map.h"


int main()
{
	rover_grid_map grid_map; 
	grid_map.init(); 

	state_rover rover(grid_map); 

	while(rover.take_turn()){

	}

}
