
#include <gtest/gtest.h>
#include "gs.cpp"


// previous tests made by Sheryl

// (0.1) Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.
TEST(preflight,check_same_type){
    bool isSameType = std::is_same<decltype(F), decltype(k)>::value;
    ASSERT_TRUE(isSameType);
    isSameType = std::is_same<decltype(u)::value_type, decltype(v)::value_type>::value;
    ASSERT_TRUE(isSameType);
}

// (0.2) Check that the variables u and v are the same size
TEST(preflight,check_same_size){
    ASSERT_EQ(u.size(), v.size());
}


// the third test and additional tests below made by Gary(Angguo)

// (0.3) Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
TEST(preflight, check_simulation_with_zero_initial_condition) {
    // Set initial conditions to u = 0 and v = 0
    u = std::vector<std::vector<double>>(width, std::vector<double>(height, 0.0));
    v = std::vector<std::vector<double>>(width, std::vector<double>(height, 0.0));

    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
    }

    // use countElementsAboveThreshold 
    double proportionAboveThreshold = countElementsAboveThreshold(threshold);

    ASSERT_EQ(proportionAboveThreshold, 0.0);
}

// # additional tests:

// (0.4) Check initial values of u and v
TEST(simulation, check_initial_values) {
    // Run initialization
    init();

    // Check that u has a value of 1.0 and v has a value of 0.0 for non-overlapping region
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (x >= 100 && x <= 200 && y >= 100 && y <= 150) {
                ASSERT_NEAR(u[x][y], 1.0, 1e-6);
                ASSERT_NEAR(v[x][y], 0.0, 1e-6);
            } else {
                ASSERT_NEAR(u[x][y], 0.0, 1e-6);
                ASSERT_NEAR(v[x][y], 0.0, 1e-6);
            }
        }
    }
}

// (0.5) Check if simulation step is working correctly and u and v are updated as expected
TEST(simulation, check_simulation_step) {
    // Run initialization
    init();

    // Save the initial state of u and v
    std::vector<std::vector<double>> initialU = u;
    std::vector<std::vector<double>> initialV = v;

    // Perform one simulation step
    simulateStep();

    // Check that u and v have been updated
    bool isUpdated = false;
    for (int x = 1; x < width - 1; ++x) {
        for (int y = 1; y < height - 1; ++y) {
            if (u[x][y] != initialU[x][y] || v[x][y] != initialV[x][y]) {
                isUpdated = true;
                break;
            }
        }
        if (isUpdated) {
            break;
        }
    }
    ASSERT_TRUE(isUpdated);
}


// (0.6) Test countElementsAboveThreshold function
TEST(simulation, check_count_elements_above_threshold) {
    // Set a specific value for v[x][y] to test countElementsAboveThreshold function
    v[50][50] = 0.2;
    v[100][100] = 0.3;
    v[150][150] = 0.4;

    // Test countElementsAboveThreshold function
    double threshold = 0.25;
    double count = countElementsAboveThreshold(threshold);
    ASSERT_EQ(count, 2.0 / (width * height));
}


// (0.7) Check if simulation correctly outputs VTK files
TEST(simulation, check_vtk_output) {
    // Run initialization
    init();

    // Perform simulations
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();

        // Write VTK file for each output interval
        if (iteration % outputInterval == 0) {
            writeVTKFile(iteration);

            // Check that the VTK file exists
            std::stringstream ss;
            ss << "output_" << iteration << ".vtk";
            std::ifstream vtkFile(ss.str());
            ASSERT_TRUE(vtkFile.good());
            vtkFile.close();
        }
    }
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
