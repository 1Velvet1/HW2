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
	
		std::ofstream out(argv[2], std::ios::binary | std::ios::out);
		std::string data = "";

		std::cout << "Enter a string to be cyphered\n";
	
		std::getline(std::cin, data);

		const size_t dataSize = data.size();

		if (!pwd_check()) {

			std::cout << "You failed to enter a password!\n";
			return 3;

		}

		char* output = gamma_infliction(data.data(), key, dataSize);	
		cyclic_shiftR(output, 4, dataSize);

		out.write(output, dataSize);
		
		out.close();

		delete[] output;

	}
	else if (mode == "decryption") {

		std::ifstream in(argv[2], std::ios::in | std::ios::binary);

		if (!in.is_open()) {

			std::cout << "The path to the file is invalid\n";
			return 4;

		}

		if (!pwd_check()) {

			std::cout << "You failed to enter a password!\n";
			return 3;

		}
		
		in.seekg(0, std::ios::end);
		const size_t dataSize = in.tellg();
		in.seekg(0, std::ios::beg);
		
		char* data = new char[dataSize];

		in.read(data, dataSize);

		std::cout << dataSize << std::endl;
				
		char* output = data;

		cyclic_shiftL(data, 4, dataSize);
		output = gamma_infliction(data, key, dataSize + 1);
		output[dataSize] = '\0';
		std::cout << output << std::endl;

		delete[] data;
		delete[] output;

	}
	else {

		std::cout << "Please enter a valid working mode [encryption/decryption]\n";
		return 2;

	}

	return 0;

}