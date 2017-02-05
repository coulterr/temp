#ifndef ROVER_SAMPLER_H
#define ROVER_SAMPLER_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

#include "rover_nav_unit.h"
#include "rover_grid_map.h"

class rover_sampler
{
	private: 
		rover_nav_unit& m_nav_unit; 
		rover_grid_map& m_grid_map; 
		std::vector<int> m_inventory; 	
	public:

		rover_sampler(rover_nav_unit& nav_unit, rover_grid_map& grid_map); 
		int get_sample(); 
		bool has_sample(); 
		int get_count(); 
		void grab_sample();
		
}; 

#endif
