class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;
            
            for (int j = 0; j < result.length(); j++) {
                if (j + 1 < result.length() && result[j] == result[j + 1]) {
                    count++;
                } else {
                    temp += to_string(count) + result[j];
                    count = 1;  
                }
            }
            
            result = temp;
        }
        
        return result;
    }
};