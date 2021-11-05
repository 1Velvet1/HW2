#include "CypherFuncs.h"

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

void cyclic_shiftR(char* data, unsigned const shiftVal, size_t len) {

	byte carryOld, carry;
	
	byte maskR = 0xff >> shiftVal;
	byte maskL = 0xff << (8 - shiftVal);

	carry = (data[0] << (8 - shiftVal)) & maskL;

	data[0] = (data[0] >> shiftVal) & maskR | (data[len - 1] << (8 - shiftVal)) & maskL;


	for (size_t i = 1; i < len; i++) {

		carryOld = carry;
		carry = (data[i] << (8 - shiftVal)) & maskL;
		data[i] = (data[i] >> shiftVal) & maskR | carryOld;

	}
	
}

void cyclic_shiftL(char* data, unsigned const shiftVal, size_t len) {

	byte carryOld, carry;

	byte maskR = 0xff >> (8 - shiftVal);
	byte maskL = 0xff << shiftVal;

	carry = (data[len - 1] >> (8 - shiftVal)) & maskR;

	data[len - 1] = (data[len - 1] << shiftVal) & maskL | (data[0] >> (8 - shiftVal)) & maskR;


	for (int i = len - 2; i > -1; i--) {

		carryOld = carry;
		carry = (data[i] >> (8 - shiftVal)) & maskR;
		data[i] = (data[i] << shiftVal) & maskL | carryOld;

	}

}