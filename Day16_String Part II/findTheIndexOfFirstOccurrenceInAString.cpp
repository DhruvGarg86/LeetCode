// LeetCode -> 28 Find the Index of the First Occurrence in a String.

// Given two strings needle and haystack, return the index of the
// first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// TC-> O((N-M+1)*M)
/*
Where:

N = length of haystack
M = length of needle

Explanation:
The loop runs N - M + 1 times.
Each time, substr(i, M) takes O(M) time because it creates a new string of length M.
Comparing two strings of length M takes O(M) time.
*/

// SC-> O(1)
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        int x = needle.size();
        int y = haystack.size();
        for (int i = 0; i <= y - x; i++)
        {
            string s = haystack.substr(i, x);
            if (s == needle)
                return i;
        }
        return -1;
    }
};