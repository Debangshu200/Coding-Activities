class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        int n = interval.size(); // size of array
        
        sort (interval.begin(), interval.end());
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            int start = interval[i][0];
            int end = interval[i][1];
            
        if(!ans.empty() && end <= ans.back()[1]) {
            continue;
        }
        
        for(int j = i + 1; j < n; j++) {
            if (interval[j][0] <= end) {
                end = max(end, interval[j][1]);
            }
            else{
                break;
            }
        }
            ans.push_back({start, end});
        }
        return ans;
    }
};