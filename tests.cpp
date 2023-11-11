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


