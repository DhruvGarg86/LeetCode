// Leet Code -> 62. Unique Paths

// There is a robot on an m x n grid. 
// The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths 
// that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// TC -> O(n-1) or (m-1)
// SC -> O(1)
// the time complexity can be of the two depending upon
// what we wrote in the code, if in m * n matrix, whichever is smaller
// take that one to take the min complexity.

class Solution {
    public:
        int uniquePaths(int m, int n) {
            // do take 2*3 matrix and do dry run before understanding the code.
            int N = m + n -2;
            int r = m-1;
            long long res = 1; // taking long long as factorial answer can skyrocket in value very easily.
            for(int i=1; i <= r; i++)
            {
                res = res * (N-r+i)/i; // finding NcR (learned in Pascal's Triangle problem)
            }
            return int(res); // converted back to int as per required in the question
        }
    };