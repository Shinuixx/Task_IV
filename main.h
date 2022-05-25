#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <bitset>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <time.h>

using namespace std;
uint8_t hammingDistance(uint8_t n1, uint8_t n2);
void pliki(const string nazwaPliku, const int licznik, const char wartosc);
void Porownanie(const char* Plik1, const char* Plik2);
void losowy(const string nazwaPliku, const int licznik, const char wartosc1, const char wartosc2);
