class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int& num:nums)
        {
            num=num%2;
        }

        auto atMost=[&](int target)
        {
            if(target<0) return 0;

            int left=0;
            int sum=0;
            int count=0;

            for(int right=0;right<nums.size();right++)
            {
                sum+=nums[right];

                while(sum>target)
                {
                    sum-=nums[left];
                    left++;
                }

                count+=right-left+1;
            }
            return count;
        };
        return atMost(k)-atMost(k-1);
    }
};