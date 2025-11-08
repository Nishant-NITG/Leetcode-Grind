class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;  
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < fruits.size()) {
            basket[fruits[right]]++;  
            right++;

            
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }

           
            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
