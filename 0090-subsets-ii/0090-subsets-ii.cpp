class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>current;

        sort(nums.begin(),nums.end());

        back(nums,0,current,result);
        return result;
    }

    void back(vector<int>&nums,int idx,vector<int>&current,vector<vector<int>>& result)
    {
        result.push_back(current);

        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1])
            {
                continue;
            }

            current.push_back(nums[i]);
            back(nums,i+1,current,result);
            current.pop_back();
        }
    }
};