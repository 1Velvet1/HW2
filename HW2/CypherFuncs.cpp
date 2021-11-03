#include "CypherFuncs.h"

void to_bin(char ch) {

	int binary[8];

	for (int n = 0; n < 8; n++)
		binary[7 - n] = (ch >> n) & 1;

	for (int n = 0; n < 8; n++)
		std::cout << binary[n] << ((n == 3 || n == 7) ? " " : "");


}


char* gamma_infliction(char const* initData, const unsigned key, size_t strLength) {

	std::mt19937 gammaKey(key);
	std::uniform_int_distribution<unsigned int> gammaGen(0, 0xff);
	unsigned int gamma;
	char* cypheredStr = new char[strLength];
	char block;


	for (size_t i = 0; i < strLength; i++) {

		gamma = gammaGen(gammaKey);
		
		memcpy(&block, initData + i, 1);
		block = block ^ gamma;
		memcpy(cypheredStr + i, &block, 1);

	}

	return cypheredStr;

}

void cyclic_shift(char* data, unsigned const shiftVal, size_t len) {
		
	unsigned char carryOld, carry;
	std::cout << len << std::endl;
	for (size_t i = 0; i < len; i++) {

		to_bin(data[i]);

	}
	unsigned char maskR = 0xff >> shiftVal;
	unsigned char maskL = 0xff << (8 - shiftVal);

	carry = data[0] << (8 - shiftVal);
	
	data[0] = (data[0] >> shiftVal) & maskR  | (data[len-1] << (8 - shiftVal)) & maskL;
	
	
	std::cout << std::endl;

	for (size_t i = 1; i < len; i++) {

		carryOld = carry;
		carry = (data[i] << (8 - shiftVal)) & maskL;
		to_bin(carryOld); std::cout << std::endl;
		to_bin((data[i] >> shiftVal) & maskR); std::cout << std::endl;
		data[i] = (data[i] >> shiftVal) & maskR | carryOld;

	}

	for (size_t i = 0; i < len; i++) {

		to_bin(data[i]);

	}

	std::cout << std::endl;

}
