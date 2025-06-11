// Leet Code -> 3. Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest
// substring without duplicate characters.

// TC -> O(N)
// SC -> O(N)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 256 possible string characters (ASCII),
        // each initialized with value zero.

        vector<int> mpp(256, -1); // SC -> O(N)
        int n = s.size();
        int left = 0, right = 0;
        int length = 0;

        // TC -> O(N)
        while (right < n)
        {
            if (mpp[s[right]] != -1)
                // this helps check if a particular character has
                // been encountered before. If not its value will be
                // -1 else it will != -1.
                left = max(mpp[s[right]] + 1, left);
            // +1, because at mpp[s[right]] it is repeating we need
            // to jump to the next character to again start checking
            // for longest sequence.

            mpp[s[right]] = right;

            length = max(length, (right - left + 1));
            right++;
        }
        return length;
    }
};