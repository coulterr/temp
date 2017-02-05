#include "rover_sampler.h"

/*
*	Performs GRAB instructions and keeps track of 
*	which samples have been collected (inventory) 
*/
rover_sampler::rover_sampler(rover_nav_unit& nav_unit, rover_grid_map& grid_map)
	:m_nav_unit(nav_unit), 
	m_grid_map(grid_map) 
{
 
}


/*
*	Adds sample at current nav_unit location to 
*	'inventory'. 
*/
int rover_sampler::get_sample()
{
	int row = m_nav_unit.get_row(); 
	int col = m_nav_unit.get_col(); 

	return m_grid_map.get_sample(row, col); 
}

/*
*	Reports whether sample at current nav_unit location
*	is already in inventory. 
*/
bool rover_sampler::has_sample()
{
	int sample = get_sample(); 

	for(int i = 0; i < m_inventory.size(); i++){
		if(m_inventory.at(i) == sample){
			return true; 
		}
	}

	return false; 
}

/*
*	Returns the number of samples contained in inventory
*/
int rover_sampler::get_count()
{
	return m_inventory.size(); 
}

/*
*	Performs GRAD instruction (adds sample at nav_unit location
	to inventory) 
*/
void rover_sampler::grab_sample()
{
	m_inventory.push_back(get_sample()); 
}
