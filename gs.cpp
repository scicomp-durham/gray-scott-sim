//gs.cpp
#include "GrayScottSimulation.h"


int main(int argc, char* argv[]) {
    //change 5 to 6
    if (argc != 6){
        std::cout << "Usage: " << argv[0] << " <Du> <Dv> <F> <k> <threshold>" << std::endl;
    }
    else{
      Du = std::stod(argv[1]);
      Dv = std::stod(argv[2]);
      F = std::stod(argv[3]);
      k = std::stod(argv[4]);
      threshold = std::stod(argv[5]);
    }
       
    init();
    std::cout << "Simulation initiated." << std::endl;

    // Main simulation loop
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
        
        // Periodically write to VTK file
        if (iteration % outputInterval == 0) {
            writeVTKFile(iteration);
        }
    }

    // count the amount of pixels above threshold at end.
    double n = countElementsAboveThreshold(threshold);
    std::cout << "Simulation completed: P(v > threshold) = " << n << std::endl;
    
    return 0;
}

