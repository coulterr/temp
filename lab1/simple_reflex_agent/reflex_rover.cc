#include <iostream>

char SimpleReflexAgent(int percept)
{
	if(percept % 5 == 0) return 'G'; 
	return 'N'; 
}



int main()
{
	int percept; 

	while(std::cin >> percept)
	{
		std::cout << "Perceived: " << percept << " Action: " << SimpleReflexAgent(percept) << "\n"; 

	}

}
