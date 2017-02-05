#ifndef STATE_ROVER_H
#define STATE_ROVER_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <tuple>

#include "rover_grid_map.h"
#include "rover_nav_unit.h"
#include "rover_camera.h"
#include "rover_sampler.h"

class state_rover
{
	private: 
		rover_grid_map& m_grid_map; 
		rover_nav_unit m_nav_unit; 
		rover_camera m_camera; 
		rover_sampler m_sampler; 
		std::vector<std::tuple<std::string, std::string> > m_field_of_vision; 
		std::string m_instruction; 
		int m_stale_count;
		int m_move_count; 

		bool has_seen(std::string direction); 
		bool is_passable(std::string direction); 
		void execute_instruction(); 
		void print_report(); 
		void print_final_summary(); 

	public:
		state_rover(rover_grid_map& grid_map);
		bool take_turn(); 



		
}; 

#endif
