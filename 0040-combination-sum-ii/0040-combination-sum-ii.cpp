class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>current;

        sort(candidates.begin(),candidates.end());

        back(candidates,0,target,current,result);
        return result;
    }

    void back(vector<int>& candidates, int start, int target,
                   vector<int>& current, vector<vector<int>>& result) 
    
    {
        if(target==0)
        {
            result.push_back(current);
            return;
        }

        if(start>=candidates.size()||candidates[start]>target) return;

        for(int i=start;i<candidates.size() && candidates[i]<=target;i++)
        {
            if(i>start && candidates[i]==candidates[i-1])
            {
            continue;
            }

            current.push_back(candidates[i]);

            back(candidates,i+1,target-candidates[i],current,result);

            current.pop_back();
        }
    }
};