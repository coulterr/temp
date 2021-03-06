#include "state_rover.h"


/*
*	State Rover class initializes sensors (camera and sampler) 
*	and nav unit. Performs actual decision making and action handling. 
*	Keeps track of Rover's recent discoveries (sight percepts). 
*/
state_rover::state_rover(rover_grid_map& grid_map)
	
	:m_grid_map(grid_map), 
	m_nav_unit(1, 1), 
	m_camera(m_nav_unit, m_grid_map),
	m_sampler(m_nav_unit, m_grid_map)

{
	m_camera.set_orientation("NORTH"); 
	m_field_of_vision.push_back(std::tuple<std::string, std::string>("NORTH", m_camera.get_visual())); 
	//stale_count keeps track of how many revisits (to visited tiles) occur
	//in a row. Value > 1 indicates loop, and will prompt take_turn to return 
	//false, indicating that all reachable samples have been found. 
	m_stale_count = 0; 
	m_move_count = 0; 
}

/*
*	Reports whether, since moving, the rover has looked in 
*	a particular direction. 
*/
bool state_rover::has_seen(std::string direction)
{
	for(int i = 0; i < m_field_of_vision.size(); i++){
		if(std::get<0>(m_field_of_vision.at(i)).compare(direction) == 0){
			return true; 
		}
	}
	return false; 
}

/*
*	Reports whether a tile (which has already been seen) is 
*	passable (clear)
*/
bool state_rover::is_passable(std::string direction)
{
	for(int i = 0; i < m_field_of_vision.size(); i++){
		if(std::get<0>(m_field_of_vision.at(i)).compare(direction) == 0){
			std::string visual = std::get<1>(m_field_of_vision.at(i)); 
			if(visual.compare("CLEAR") == 0){
				return true; 
			}
		}
	}
	return false; 
}

/*
*	Prints report including current percept state and
*	decision (not yet carried out) 
*/
void state_rover::print_report()
{
	std::cout << "Position: <" << m_nav_unit.get_row() << ", " << m_nav_unit.get_col() << "> ";
	std::cout << "Looking: " << m_camera.get_orientation() << " ";
	std::cout << "Perceived: <" << m_sampler.get_sample() << ", " << m_camera.get_visual() << "> ";
	std::cout << "Action: " << m_instruction << std::endl; 
}

/*
*	Prints final summary, including number of samples collected
*	and total move orders. 
*/
void state_rover::print_final_summary()
{
	std::cout << "Total Compounds Collected: " << m_sampler.get_count() << std::endl; 
	std::cout << "Total Moves: " << m_move_count << std::endl; 

}

/*
*	Performs task for given instruction	
*/
void state_rover::execute_instruction()
{
	if(m_instruction.compare("GRAB") == 0){

		m_sampler.grab_sample(); 
	
	}else if(m_instruction.compare("LOOKNORTH") == 0){
	
		m_camera.set_orientation("NORTH"); 
		m_field_of_vision.push_back(std::tuple<std::string, std::string>("NORTH", m_camera.get_visual()));
	
	}else if(m_instruction.compare("LOOKSOUTH") == 0){
	
		m_camera.set_orientation("SOUTH"); 
		m_field_of_vision.push_back(std::tuple<std::string, std::string>("SOUTH", m_camera.get_visual()));
	
	}else if(m_instruction.compare("LOOKEAST") == 0){

		m_camera.set_orientation("EAST");  
		m_field_of_vision.push_back(std::tuple<std::string, std::string>("EAST", m_camera.get_visual()));

	}else if(m_instruction.compare("GONORTH") == 0){
		
		m_field_of_vision.clear();
		m_nav_unit.move_to("NORTH"); 

	}else if(m_instruction.compare("GOSOUTH") == 0){
	
		m_field_of_vision.clear();
		m_nav_unit.move_to("SOUTH"); 
	
	}else if(m_instruction.compare("GOEAST") == 0){

		m_field_of_vision.clear(); 
		m_nav_unit.move_to("EAST"); 

	}



}


/*
*	Determines next move based on information from sensors and 
*	memory of surroundings. Returns false once it has successfully 
*	collected all reachable samples.
*/
bool state_rover::take_turn()
{
	if(!m_sampler.has_sample()){
		
		m_instruction = "GRAB"; 
	
	}else if(!has_seen("NORTH")){
		
		m_instruction = "LOOKNORTH";
	
	}else if(!has_seen("EAST")){
	
		m_instruction = "LOOKEAST"; 
	
	}else if(!has_seen("SOUTH")){
		
		m_instruction = "LOOKSOUTH"; 
	
	}else if(is_passable("NORTH") && !m_nav_unit.has_been("NORTH")){
		
		m_stale_count = 0; 
		++m_move_count; 
		m_instruction = "GONORTH"; 
	
	}else if(is_passable("SOUTH") && !m_nav_unit.has_been("SOUTH")){
		
		m_stale_count = 0; 
		++m_move_count; 
		m_instruction = "GOSOUTH"; 

	}else if(is_passable("EAST")){
		
		m_stale_count = 0; 
		++m_move_count; 
		m_instruction = "GOEAST"; 

	}else if(is_passable("NORTH")){
		
		++m_stale_count; 
		
		if(m_stale_count > 1){
			print_final_summary(); 
			return false; 
		}else{
			++m_move_count; 
			m_instruction = "GONORTH"; 
		}

	}else if(is_passable("SOUTH")){
		
		++m_stale_count; 
		
		if(m_stale_count > 1){
			return false; 
			print_final_summary(); 
		}else{
			++m_move_count; 
			m_instruction = "GOSOUTH"; 
		}
	}else{
		print_final_summary(); 
		return false; 
	}

	print_report(); 
	execute_instruction(); 

	return true; 	
}





