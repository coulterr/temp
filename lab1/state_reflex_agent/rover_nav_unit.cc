#include "rover_nav_unit.h"


rover_nav_unit::rover_nav_unit(int row, int col)
	:m_row(row), 
	m_col(col)
{
}

void rover_nav_unit::move_to(std::string direction)
{
	m_visited.push_back(std::tuple<int, int>(m_row, m_col)); 

	if(direction.compare("NORTH") == 0){
		++m_row; 
	}else if(direction.compare("EAST") == 0){
		++m_col; 
	}else if(direction.compare("SOUTH") == 0){
		--m_row;
	}else if(direction.compare("WEST") == 0){
		--m_col; 
	}
}

bool rover_nav_unit::has_been(std::string direction)
{
	int dest_row = m_row;
	int dest_col = m_col; 

	if(direction.compare("NORTH") == 0){
		++dest_row; 
	}else if(direction.compare("EAST") == 0){
		++dest_col; 
	}else if(direction.compare("SOUTH") == 0){
		--dest_row;
	}else if(direction.compare("WEST") == 0){
		--dest_col; 
	}

	for(int i = 0; i < m_visited.size(); i++){
		if(std::get<0>(m_visited.at(i)) == dest_row && 
		   std::get<1>(m_visited.at(i)) == dest_col){
			return true; 
		}
	}

	return false; 
}

int rover_nav_unit::get_row()
{
	return m_row; 
}

int rover_nav_unit::get_col()
{
	return m_col; 
}
