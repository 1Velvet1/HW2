#include <cstdlib>
#include <random>
#include <string>
#include <Windows.h>

#ifndef CYPHERFUNCS___H
#define CYPHERFUNCS___H

const unsigned key = 2112;
const unsigned password = 391452;

char* gamma_infliction(char const* initData, const unsigned key, size_t strLength);

void cyclic_shiftR(char* data, unsigned const shiftVal, size_t len);

void cyclic_shiftL(char* data, unsigned const shiftVal, size_t len);

#endif