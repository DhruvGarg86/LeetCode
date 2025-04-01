// Leet Code -> 56. Merge Intervals

// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the 
// non-overlapping intervals that cover all the intervals in the input.

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int n = intervals.size();
            
            // Sorting the vector of vectors
            sort(intervals.begin(), intervals.end());
    
            // Creating an vector to store the ans
            vector<vector<int>> ans;
    
            for(int i = 0; i < n; i++)
            {
                if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                    ans.push_back(intervals[i]);
                }
                else{
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }
            }
            return ans; 
            // Time Complexity :- O(nlogn)
            // Space Complexity :- O(n)
            // in worst case if no intervals are to overlap
        }   
    };