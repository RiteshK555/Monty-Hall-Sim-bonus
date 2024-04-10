#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

//random number generator
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]){
	
	if(argc == 1){

		//check for args
		std::cout << "arguments not provided" << "\n";

	}	
	else if(argc == 2){

		//check for args
		std::cout << "num doors opened by host" << "\n";

	}
	else if(argc == 3){

		//num doors
		int num_doors = 0;
		try{
			num_doors = std::stoi(argv[1]);

			if(num_doors <= 0){

				//strictly positive values allowed
				std::cout << "only positive values allowed" <<  "\n";
				return 0;

			}
		}
		catch(const std::invalid_argument& e){

			//check invalid args
			std::cout << "invalid argument " << e.what() << "\n";
			return 0;

		}
		catch(const std::out_of_range& e){

			//check out of range
			std::cout << "out of range " << e.what() << "\n";
			return 0;

		}

		//num doors opened by host
		int num_doors_opened_by_host = 0;
		try{
			num_doors_opened_by_host = std::stoi(argv[2]);

			if(num_doors_opened_by_host <= 0){

				//strictly positive values allowed
				std::cout << "strictly positive values allowed" << "\n";
				return 0;

			}
		}
		catch(const std::invalid_argument& e){

			//check invalid args
			std::cout << "invalid argument " << e.what() << "\n";
			return 0;

		}
		catch(const std::out_of_range& e){

			//check out of range 
			std::cout << "out of range " << e.what() << "\n";
			return 0;

		}

		if(num_doors_opened_by_host + 2 > num_doors){

			//check if possible to open doors
			std::cout << "it is not possible to open the doors specified" << "\n";
			return 0;

		}

		//output
		std::cout << "---output---" << "\n";

		//for sticking
		// 1 / n
		std::cout << "sticking: " << ((float) 1 / num_doors) * 100<< "\n";

		//for switching
		// ((n - 1) / n) * (1 / (n - p - 1))
		std::cout << "switching: " << ((((float)(num_doors - 1)) / num_doors) * ((float) 1 / (num_doors - num_doors_opened_by_host - 1))) * 100<< "\n";

	}
	else{

		//more args provided
		std::cout << "more than 3 arguments provided" << "\n";	

	}

	return 0;
}