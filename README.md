# gray-scott-sim
**_Da Cui GS coursework for Professional Skills_**

**_Git Commands_**

Use the Git command to clone the GitHub repository to your local machine. 

`git clone <repositoryURL>`


Create a new branch, add all changes to that branch, commit the changes, and finally push the branch to the remote repository for sharing and collaboration with others.
```
git checkout -b <newBranchName>
git add .
git commit -m "Descriptive commit message"
git push origin <yourBranchName>
```


**_TEST 0.3_** 

In accordance with the requirements of Test (0.3) in the coursework, firstly, all elements of 'u' and 'v' are initialised to 0 at the start of the test, and 'F' and 'k' are set to 0 to check that the simulation produces a mathematically correct answer. 

After that, 'ASSERT_EQ' is used to assert that all elements of the u and v matrices are equal to zero. If the simulation system is correct, then after a sufficient number of iterations with zero initial conditions, all elements in 'u' and 'v' should still be zero.

Finally, 'ASSERT_EQ' is used to assert that proportionAboveThreshold is equal to zero, further validating whether the system correctly simulates under zero initial conditions.
