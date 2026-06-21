class Solution {
public:

    int daysRequired(vector<int>& weights, int capacity)
    {
        int days = 1;
        int load = 0;

        for(int weight : weights)
        {
            if(load + weight > capacity)
            {
                days++;
                load = weight;
            }
            else
            {
                load += weight;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int l = *max_element(weights.begin(), weights.end());

        int r = accumulate(weights.begin(),
                           weights.end(),
                           0);

        int ans = r;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            int needed = daysRequired(weights, mid);

            if(needed <= days)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};