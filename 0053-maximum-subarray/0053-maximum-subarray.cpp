class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current=0;

        int maxSum=INT_MIN;

        for(int num:nums)
        {
            current=max(num,current+num);

            maxSum=max(maxSum,current);
        }
        return maxSum;
        
    }
};