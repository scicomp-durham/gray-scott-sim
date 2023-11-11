// GrayScottSimulation.h
#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>

// Declare simulation parameters
extern const int width;
extern const int height;
extern double Du;
extern double Dv;
extern double F;
extern double k;
extern double threshold;
extern const double dt;
extern const int numIterations;
extern const int outputInterval;

// Declare grid and constants
extern std::vector<std::vector<double>> u;
extern std::vector<std::vector<double>> v;

// Declare functions
void init();
void writeVTKFile(int iteration);
void simulateStep();
double countElementsAboveThreshold(double threshold);



