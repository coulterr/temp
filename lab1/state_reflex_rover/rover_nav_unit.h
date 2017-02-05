#ifndef rover_nav_unit_H
#define rover_nav_unit_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "rover_grid_map.h"


class rover_nav_unit
{
	private: 
		int m_row;  
		int m_col;
		std::vector<std::tuple<int, int> > m_visited; 	

	public:
		rover_nav_unit(int row, int col); 
		void move_to(std::string direction); 
		bool has_been(std::string direction); 
		int get_row(); 
		int get_col(); 
}; 

#endif
