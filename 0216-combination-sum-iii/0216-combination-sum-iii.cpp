class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int>current;
        back(1,k,n,current,result);
        return result;

    }

    void back(int idx,int k,int n,vector<int>&current,vector<vector<int>>& result)
    {

        //base case: found a valid combination
        if(current.size()==k && n==0)
        {
            result.push_back(current);
            return;
        }

        if(current.size()>k || n<0)
        {
            return;
        }

        if(idx>9) return;

        //not enough numbers left to reach k
        if(current.size()+(9-idx+1)<k) return;

        current.push_back(idx);
        back(idx+1,k,n-idx,current,result);
        current.pop_back();

        back(idx+1,k,n,current,result);



    }
};