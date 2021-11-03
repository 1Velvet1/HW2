#include <iostream>
#include <fstream>
#include "CypherFuncs.h"

bool pwd_check() {

	size_t numOfTries = 0;
	unsigned pwd;

	std::cout << "Please enter password to continue: ";


	while (numOfTries < 5) {

		std::cin >> pwd;

		if (pwd == password) {
			
			return true;

		}
		else { 
			
			std::cout << "Invalid password. Tries left: " << 4 - numOfTries << std::endl;
			
			numOfTries++; 
		
		}

	}

	return false;

}


int main(int argc, char* argv[]) {

	
	

	if (argc != 3) {

		std::cout << "Invalid number of arguements\n2 should be given\n";
		return 1;

	}	
	
	std::string mode = argv[1];

	if(mode == "encryption"){
	
		std::ofstream out(argv[2]);
		std::string data = "";

		std::cout << "Enter a string to be cyphered\n";
	
		std::getline(std::cin, data);

		if (!pwd_check()) {

			std::cout << "You failed to enter a password!\n";
			return 3;

		}

		char* output = gamma_infliction(data.data(), key, data.size());

		for (size_t i = 0; i < data.size(); i++)
			out << output[i];

		out << std::endl;

		char* output2 = gamma_infliction(output, key, data.size());

		for (size_t i = 0; i < data.size(); i++)
			out << output2[i];
		
		out << std::endl;

		cyclic_shift(output, 4, data.size());

		for (size_t i = 0; i < data.size(); i++)
			out << output[i];

	//	delete[] output;

	}
	else if (argv[1] == "decryption") {


	}
	else {

		std::cout << "Please enter a valid working mode [encryption/decryption]\n";
		return 2;

	}

	return 0;

}