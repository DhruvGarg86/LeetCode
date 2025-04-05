// Leet Code -> 74. Search A 2D Matrix

// You are given an m x n integer matrix matrix with the following two properties:

// -Each row is sorted in non-decreasing order.
// -The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.


class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int low = 0;
            int m = matrix.size(); // number of rows
            int n = matrix[0].size(); // number of columns
            int high = m * n -1;
            //  implementing binary search -> the 2d is already sorted
            //  Just need to convert 2D to 1D array.
            while(low <= high)
            {
                int mid = (low + high) / 2;
                // converting 2D - 1D Matrix
                int row = mid / n;
                int col = mid % n;
                if(matrix[row][col] == target) 
                    return true;
                else if(matrix[row][col] < target) 
                    low = mid + 1;
                else 
                    high = mid - 1;
            }
            return false;
        }
    };


    
// For some reason this solution of TC->O(m*n) is also accepted on LeetCode, 
// even though question is asking for TC->(O(log(m*n)))
// just for note -> don't use this code as solution.

// class Solution {
//     public:
//         bool searchMatrix(vector<vector<int>>& matrix, int target) {
//                 //matrix.size() -> return the size of row in the matrix
//             for(int i = 0; i < matrix.size(); i++) {
//                 //matrix[0].size() -> return the size of column[0] in the matrix
//                 for(int j = 0 ;j < matrix[0].size(); j++) {
//                     if(matrix[i][j] == target)
//                         return true;
//                 }
//             }
//             return false;
//         }
//     };