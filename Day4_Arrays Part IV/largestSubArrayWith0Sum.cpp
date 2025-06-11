// GFG -> Largest subarray with 0 sum

// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Given an array arr containing both positive and negative integers,
// the task is to compute the length of the largest subarray that has a sum of 0.

// Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
// Output: 5
// Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].

#include <bits/stdc++.h> 
using namespace std;

int getLongestSubarray(vector<int> &a, int k)
{
    map<int, int> preSum;
    long long sum = 0;
    int maxLen = 0; 
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
            maxLen = max(maxLen, i + 1);
        long long rem = sum - k;
        if (preSum.find(rem) != preSum.end())
        {
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }
        if (preSum.find(sum) == preSum.end())
        {
            preSum[sum] = i;
        }
    }
    return maxLen;
}
