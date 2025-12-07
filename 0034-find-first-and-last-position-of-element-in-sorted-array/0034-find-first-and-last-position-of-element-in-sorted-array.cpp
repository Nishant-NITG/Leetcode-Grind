class Solution {
public:

    int first(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        int mid;
        int ans=-1;

        while(low<=high)
        {
            int mid=low+ (high-low)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;

            }
            else 
            {
                high=mid-1;
            }
        }
        return ans;
    
    }
    int last(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        int mid;
        int ans=-1;

        while(low<=high)
        {
            int mid=low+ (high-low)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;

            }
            else 
            {
                high=mid-1;
            }
        }
        return ans;
    }




    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),last(nums,target)};
        
    }
};