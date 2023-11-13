# gray-scott-sim
**_Da Cui GS coursework for Professional Skills_**



**_TEST 0.3_** 

In accordance with the requirements of Test (0.3) in the coursework, firstly, all elements of 'u' and 'v' are initialised to 0 at the start of the test, and 'F' and 'k' are set to 0 to check that the simulation produces a mathematically correct answer. 

After that, 'ASSERT_EQ' is used to assert that all elements of the u and v matrices are equal to zero. If the simulation system is correct, then after a sufficient number of iterations with zero initial conditions, all elements in 'u' and 'v' should still be zero.

Finally, 'ASSERT_EQ' is used to assert that proportionAboveThreshold is equal to zero, further validating whether the system correctly simulates under zero initial conditions.
