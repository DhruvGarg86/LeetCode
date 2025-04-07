// Leet Code -> 229. Majority Element II

// Given an integer array of size n, find all elements 
// that appear more than ⌊ n/3 ⌋ times.

// Also Known as Boyer-Moore Majority Vote Algorithm (courtesy of Chat-GPT for identifying ONLY the name of algo)

// TC -> O(n)
// SC -> O(2) -> O(1)
// we are only using a list that stores a maximum of 2 elements. 
// The space used is so small that it can be considered constant.
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int count1 = 0, count2 = 0;
            int el1 = INT_MIN, el2 =INT_MIN;
            int n = nums.size();
            for(int i = 0; i < n; i++) {
                if(count1 == 0 && el2 != nums[i])
                {
                    count1 = 1; 
                    el1 = nums[i];
                }
                else if(count2 == 0 && el1 != nums[i])
                {
                    count2 = 1; 
                    el2 = nums[i];
                }
                else if(nums[i] == el1)
                {
                    count1++;
                }
                else if(nums[i] == el2)
                {
                    count2++;
                }
                else{
                    count1--;
                    count2--;
                }
            }
            vector <int> ls;
            count1 = 0, count2 = 0;
            for(int i = 0; i < n; i++)
            {
                if(el1 == nums[i]) count1++;
                if(el2 == nums[i]) count2++;
            }
            int mini = int(n/3) + 1;
            if(count1 >= mini)
                ls.push_back(el1);
            if(count2 >= mini)
                ls.push_back(el2);
            sort(ls.begin(),ls.end());
            return ls;
        }
    };