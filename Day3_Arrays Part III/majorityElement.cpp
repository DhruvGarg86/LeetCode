// Leet Code -> 169. Majority Element

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

// Also Known as Boyer-Moore Majority Vote Algorithm (courtesy of Chat-GPT for identifying ONLY the name of algo)
// TC -> O(n)
// SC -> O(1)
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            int element;
            int count = 0; 
            // Below logic helps to identitfy the possible element that may become an majority element. 
            for(int i = 0; i < n; i++)
            {
                if(count == 0)
                {
                    count = 1;
                    element = nums[i];
                }
                else if(nums[i] == element)
                    count++;
                else
                    count--;
            }
            int count1 = 0;
            // Verfying the element taken above does follow the majority element condition
            for(int i = 0; i < n; i++)
            {
                if(nums[i] == element) count1++;
            }
            if(count1 > (n/2))
                return element;
            return -1;
        }
    };