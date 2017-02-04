#include "rover_sampler.h"


rover_sampler::rover_sampler(rover_nav_unit& nav_unit, rover_grid_map& grid_map)
	:m_nav_unit(nav_unit), 
	m_grid_map(grid_map) 
{
 
}


int rover_sampler::get_sample()
{
	int row = m_nav_unit.get_row(); 
	int col = m_nav_unit.get_col(); 

	return m_grid_map.get_sample(row, col); 
}

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

int rover_sampler::get_count()
{
	return m_inventory.size(); 
}

void rover_sampler::grab_sample()
{
	m_inventory.push_back(get_sample()); 
}
