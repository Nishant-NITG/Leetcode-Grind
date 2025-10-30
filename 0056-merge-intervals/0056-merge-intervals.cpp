class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
       
        vector<vector<int>> merged;
        
       
        for (auto current : intervals) {
            
            
            if (merged.empty() || merged.back()[1] < current[0]) {
                merged.push_back(current); 
            } 
            
            else {
                merged.back()[1] = max(merged.back()[1], current[1]);
            }
        }
        
        
        return merged;
    }
};
