// Leet Code -> 14. Longest Common Prefix

// Write a function to find the longest common
// prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// TC -> O(NlogN * K) k = length of first String in vector
// SC -> O(K) k = length of common prefix in all strings
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        sort(strs.begin(), strs.end()); // O(NlogN)
        string first = strs[0];
        string last = strs.back();
        int i = 0;
        while (i < first.size() && i < last.size() && first[i] == last[i])
        {
            i++;
        }
        return first.substr(0, i);
    }
};