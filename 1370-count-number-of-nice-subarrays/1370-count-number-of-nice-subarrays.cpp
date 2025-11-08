class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0]=1;

        int sum=0,ans=0;

        for(int num:nums)
        {
            if(num%2==1)
            {
                sum+=1;
            }

            if(prefixCount.count(sum-k))
            {
                ans+=prefixCount[sum-k];
            }

            prefixCount[sum]++;
        }
        return ans;
    }
};