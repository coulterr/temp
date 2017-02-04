#include "rover_grid_map.h"

/*
*	Custom split function. Converts dilimiter-separated string
*	into vector of strings. 
*/
std::vector<std::string> rover_grid_map::split(std::string line, char delim)
{
	std::vector<std::string> tokens;

	if(line.find_last_of(delim) == line.length() - 1) line = line.substr(0, line.length() - 1); 

	while(line.find_last_of(delim) != std::string::npos){
		tokens.insert(tokens.begin(), line.substr(line.find_last_of(delim) + 1, line.length())); 
		line = (line.substr(0, line.find_last_of(delim)));  
	}

	tokens.insert(tokens.begin(), line); 

	return tokens; 
}


/*
*	Reads in and stores map data from system.in
*/
void rover_grid_map::init()
{
	int count = 1; 

	std::string line;

	while(std::getline(std::cin, line)){
	
		std::vector<std::string> tokens = split(line, ','); 
	
		if(std::stoi(tokens.at(0)) != count){
			std::cout << "Error: invalid formatting" << std::endl;
			exit(1); 
		}

		for(int i = 1; i < tokens.size(); i+=2){
			if(count == 1){
				visuals_one.push_back(tokens.at(i)); 
				samples_one.push_back(std::stoi(tokens.at(i+1))); 
			}else if(count == 2){
				visuals_two.push_back(tokens.at(i)); 
				samples_two.push_back(std::stoi(tokens.at(i+1))); 
			}
		}

		++count; 
	}
}


/*
*	Prints readout of grid, in cardinal order. 
*/
void rover_grid_map::print_readout()
{
	for(int i = 0; i < samples_two.size(); i++){
		std::cout << visuals_two.at(i); 
		std::cout << samples_two.at(i) << " "; 
	}
		std::cout << std::endl;
	
	for(int i = 0; i < samples_one.size(); i++){
		std::cout << visuals_one.at(i); 
		std::cout << samples_one.at(i) << " ";
	}
		std::cout << std::endl;
}


/*
*	Returns string corresponding to status of specified tile 
*	(blocked or clear). Base index for either row or col is 1.
*/
std::string rover_grid_map::get_visual(int row, int col)
{
	if(row == 1){
		if(col >= 1 && col <= visuals_one.size()){
			return visuals_one.at(col - 1); 
		}

	}else if(row == 2){
		if(col >= 1 && col <= visuals_two.size()){
			return visuals_two.at(col - 1); 
		}
	}

	return "NULL"; 
}


/*
*	Returns integer corresponding to sample at specified grid 
*	(0 - 25). Base index for either row or col is 1.
*
*	Requests for NULL tiles will throw error, since
*	rover cannot move to NULL tiles.
*/
int rover_grid_map::get_sample(int row, int col)
{	
	if(row == 1){
		if(col >= 1 && col <= samples_one.size()){
			return samples_one.at(col - 1); 
		}else{
			std::cout << "Error: attempt to sample invalid col" << std::endl;
			exit(1); 
		}

	}else if(row == 2){
		if(col >= 1 && col <= samples_two.size()){
			return samples_two.at(col - 1); 
		}else{
			std::cout << "Error: attempt to sample invalid col" << std::endl;
			exit(1); 
		}
	}else{
		std::cout << "Error: attempt to sample invalid row" << std::endl;
		exit(1); 
	}
}




