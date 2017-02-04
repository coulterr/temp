#ifndef ROVER_GRID_MAP_H
#define ROVER_GRID_MAP_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

class rover_grid_map
{
	private: 
		std::vector<std::string> visuals_one; 
		std::vector<std::string> visuals_two; 
		std::vector<int> samples_one; 
		std::vector<int> samples_two; 

		std::vector<std::string> split(std::string line, char delim); 

	public:
		void init(); 
		void print_readout(); 
		int get_sample(int row, int col); 
		std::string get_visual(int row, int col); 
		
}; 

#endif
