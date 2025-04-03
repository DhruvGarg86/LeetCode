// Not A Leet Code Problem
// Link To The Problem: https://www.interviewbit.com/problems/repeat-and-missing-number-array


// You are given a read only array of n integers from 1 to n.
// Each integer appears exactly once except A which appears twice and B which is missing.
// Return A and B.

// Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
// Note that in your output A should precede B.

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long long S1n = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1))/6 ;
    long long S1 = 0;
    long long S2 = 0;
    for(int i = 0 ;i < n; i++)
    {
        S1 += A[i];
        S2 += long long(A[i]) * long long(A[i]); // to prevent memory overflow
    }
    long long val1 = S1 - S1n; // x -y 
    long long val2 = S2 - S2n;
    val2 = val2/val1; // (x^2-y^2)/(x-y) -> (x+y)
    
    long long x = (val1+ val2) / 2; // Repeated number
    long long y = x - val1; // Missing Number
    return {int(x), int(y)};
    }


