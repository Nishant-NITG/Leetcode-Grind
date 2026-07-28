class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        if (nums.size() <= 1) return true;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                count++;
            }
        }

        if(count==0)
        {
            return true;
        }
        else if(count==1)
        {
            return nums[0]>=nums[nums.size()-1];
        }

        else{
            return false;
        }
        
    }
};