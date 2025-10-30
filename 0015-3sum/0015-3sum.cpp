class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n-2;i++)
        {
            if(i>0 and nums[i-1]==nums[i])
            {
                continue;
            }

            if(nums[i]>0)
            {
                break;

            }

            int left=i+1;
            int right=n-1;
            int target=-nums[i];

            while(left<right)
            {
                int currsum=nums[left]+nums[right];

                if(currsum==target)
                {
                    result.push_back({nums[i],nums[left],nums[right]});

                    while(left<right && nums[left]==nums[left+1])
                    {
                        left++;
                    }
                    while(right>left && nums[right]==nums[right-1])
                    {
                        right--;
                    }

                     left++;
                right--;
                }

                

                else if (currsum < target) {
                    
                    left++;
                } else {
                    
                    right--;
                }
            }
        }
        return result;
    }
};