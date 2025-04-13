// Leet Code -> 3. Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest 
// substring without duplicate characters.

// TC -> O(N)
// SC -> O(N)


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // 256 possible strign characters (ASCII),
            // each initialized with value zero.

            vector<int> mpp(256, -1); // SC -> O(N)
            int n = s.size();
            int left = 0 , right = 0;
            int length = 0;

            //TC -> O(N)  
            while(right < n) { 
                if(mpp[s[right]] != -1)
                    left = max(mpp[s[right]] +1, left);

                mpp[s[right]] = right;
                
                length = max(length, (right - left + 1));
                right++;
            }
            return length;
        }
    };