class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int zeroes=0;
        int len=0;

        while(r<n)
        {
            if(nums[r]==0) zeroes++;

            r++;

            while(zeroes>k)
            {
                if(nums[l]==0)
                {
                    zeroes--;
                }
                l++;
            }
            len=max(len,r-l);
        }
        return len;
    }
};