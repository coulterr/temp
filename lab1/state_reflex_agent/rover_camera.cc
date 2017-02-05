#include "rover_camera.h"

/*
*	Keeps track of camera orientation and reports 
*	visual percepts. 
*/
rover_camera::rover_camera(rover_nav_unit& nav_unit, rover_grid_map& grid_map)
	:m_nav_unit(nav_unit),
	m_grid_map(grid_map)
{
	m_orientation = "NORTH"; 
}

/*
*	Reports direction 'camera' is facing	
*/
std::string rover_camera::get_orientation()
{
	return m_orientation; 
}

/*
*	Sets direction 'camera' is facing 
*/
void rover_camera::set_orientation(std::string orientation)
{
	m_orientation = orientation; 
}

/*
*	Gets visual status (clear/boulder/NULL) for tile camera
*	is facing. 
*/
std::string rover_camera::get_visual()
{
	int row = m_nav_unit.get_row(); 
	int col = m_nav_unit.get_col(); 

	if(m_orientation.compare("NORTH") == 0){
		return m_grid_map.get_visual(row + 1, col); 
	}else if(m_orientation.compare("EAST") == 0){
		return m_grid_map.get_visual(row, col + 1); 
	}else if(m_orientation.compare("SOUTH") == 0){
		return m_grid_map.get_visual(row - 1, col); 
	}else if(m_orientation.compare("WEST") == 0){
		return m_grid_map.get_visual(row, col - 1);
	}else{
		std::cout << "Error: Attempt to glimpse in invalid cardinal direction" << std::endl; 
	}
}



