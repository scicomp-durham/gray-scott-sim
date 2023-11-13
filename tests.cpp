//test.cpp
#include <gtest/gtest.h>
#include "GrayScottSimulation.h"
#include <typeinfo>



TEST(ModelParametersTest, TypeMatch) {

    EXPECT_EQ(typeid(F).name(), typeid(u[0][0]).name());
    EXPECT_EQ(typeid(k).name(), typeid(u[0][0]).name());

    std::cout << "Type of F: " << typeid(F).name() << std::endl;
    std::cout << "Type of k: " << typeid(k).name() << std::endl;
    std::cout << "Type of u[0][0]: " << typeid(u[0][0]).name() << std::endl;
}

TEST(simulation, check_simulation_with_zero_initial_condition) {
    // Set initial conditions to u = 0 and v = 0
    u = std::vector<std::vector<double>>(width, std::vector<double>(height, 0.0));
    v = std::vector<std::vector<double>>(width, std::vector<double>(height, 0.0));
    F = 0.0;
    k = 0.0;
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
    }
    // check all zero
    for (int i = 0; i < u.size(); i++)
    {
        for (int j = 0; j < u[i].size(); j++)
        {
            ASSERT_EQ(u[i][j], 0);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            ASSERT_EQ(v[i][j], 0);
        }
    }
    // use countElementsAboveThreshold 
    double proportionAboveThreshold = countElementsAboveThreshold(threshold);

    ASSERT_EQ(proportionAboveThreshold, 0.0);
}
