// Leet Code -> 1. Two Sum

// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution,
//  and you may not use the same element twice.
// You can return the answer in any order.

 
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> mpp; // using a hash map, named 'mpp'
            int n = nums.size();
            for(int i = 0 ; i < n; i++)
            {
                int a = nums[i];
                int b = target - a; // a + b = target
                if(mpp.find(b) != mpp.end())
                    return {mpp[b], i};
            mpp[a] = i;
            }
        return {-1, -1}; // if no solution is found
        }
    };