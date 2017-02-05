#ifndef rover_camera_H
#define rover_camera_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "rover_grid_map.h"
#include "rover_nav_unit.h"

class rover_camera
{
	private: 
		rover_nav_unit& m_nav_unit; 
		rover_grid_map& m_grid_map; 
		std::string m_orientation; 

	public:
		rover_camera(rover_nav_unit& nav_unit, rover_grid_map& grid_map); 
		std::string get_orientation(); 
		void set_orientation(std::string orientation); 
		std::string get_visual(); 	
}; 

#endif
