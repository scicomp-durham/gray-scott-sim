#include "acutest.h"

int add(int a, int b) {
    return a + b;
}

void test_add(void) {
    TEST_CHECK(add(2, 2) == 4);
    TEST_CHECK(add(-1, 1) == 0);
    
    TEST_MSG("Expected %d, got %d", 4, add(2, 2));
}

TEST_LIST = {
    {"add", test_add},
    {NULL, NULL}
};
