class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st;
        vector<long long>arr;
        
        for(int x:nums)
        {
            long long curr=x;

            while(!st.empty() && st.top()==curr)
            {
                curr*=2;
                st.pop();
            }
            st.push(curr);
        }

        while(!st.empty())
        {
            arr.push_back(st.top());
            st.pop();

        }

        reverse(arr.begin(),arr.end());
        return arr;

    }
};