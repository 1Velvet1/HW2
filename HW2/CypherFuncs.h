#include <cstdlib>
#include <random>
#include <iostream>
#include <Windows.h>
#include <string>

#ifndef CYPHERFUNCS___H
#define CYPHERFUNCS___H

const unsigned key = 2112;
const unsigned password = 391452;

char* gamma_infliction(char const* initData, const unsigned key, size_t strLength);

void cyclic_shift(char* data, unsigned const shiftVal, size_t len);


#endif