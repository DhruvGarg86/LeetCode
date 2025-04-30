// Leet Code -> 485. Max Consecutive Ones

// Given a binary array nums, return the maximum
//  number of consecutive 1's in the array.


// TC -> O(N)
// SC -> O(1)
class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int count = 0;
            int maxm = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1)
                    count++;
                else
                    count = 0;
                maxm = max(count, maxm);
            }
            return maxm;
        }
    };