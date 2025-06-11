// LeetCode -> 242 Valid Anagram

// Given two strings s and t, return true if t 
// is an anagram of s, and false otherwise.

// TC-> O(N)
// SC-> O(1) + O(1) -> O(1) {because only 26 characters are ther in alphabet which is constant}

class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char, int> map1;
       unordered_map<char, int> map2;
       for(char c : s){
            map1[c]++;
       }
       for(auto c : t ){
            map2[c]++;      
       }
       return map1 == map2;
    }
};