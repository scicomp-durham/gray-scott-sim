#include <gtest/gtest.h>
#include "gs.cpp" // consider your code is in this file and location

class SimulationTest : public ::testing::Test {
protected:
    void SetUp() override {
        init();
    }
};

TEST_F(SimulationTest, CountElementsAboveThreshold) {
    double threshold = 0.5;
    double result = countElementsAboveThreshold(threshold);
    EXPECT_GE(result, 0.0);
    EXPECT_LE(result, 1.0);
}
