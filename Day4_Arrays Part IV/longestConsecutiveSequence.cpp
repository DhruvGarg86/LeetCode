// Leet Code -> 128. Longest Consecutive Sequence

// Given an unsorted array of integers nums, 
// return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.


// TC -> O(3N) -> O(N)
// SC -> O(N)
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            if (n == 0)
                return 0;
            int longest = 1;
            unordered_set<int> st; // Using unordered set
            for (int i = 0; i < n; i++) { // TC -> O(N)
                st.insert(nums[i]);
            }
            for (auto it : st) {  // will take TC as O(N^2) in worst case
                if (st.find(it - 1) == st.end()) {
                    int count = 1;
                    int x = it;

                    // Counting consecutive numbers
                    while (st.find(x + 1) != st.end()) {  // TC -> O(2N)
                        x = x + 1;
                        count = count + 1;
                    }
                    longest = max(longest, count);
                }
            }
            return longest;
        }
    };