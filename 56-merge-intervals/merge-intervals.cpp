class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(); // size of array
        
        //sort the given intervals:
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
        // If the current interval does not lie int he last interval
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            
        //If the current inetrval lies in the last inetrval:
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};