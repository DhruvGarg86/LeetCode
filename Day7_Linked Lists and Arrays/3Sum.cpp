// Leet Code -> 15. 3Sum

// Given an integer array nums, return all the triplets 
// [nums[i], nums[j], nums[k]] such that i != j, i != k, 
// and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set 
// must not contain duplicate triplets.

// TC -> O(NlogN) + O(N*N) 
// SC -> O(No of Unique Triplets)
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans;
            int n = nums.size();
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                int j = i + 1;
                int k = n - 1;
                while(j < k){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum > 0) {
                        k--;
                    }
                    else if(sum < 0){
                        j++;
                    }
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j < k && nums[j] == nums[j-1]) j++;
                        while(j < k && nums[k] == nums[k+1]) k--;
                    }
                }
            }
            return ans;
        }
    };