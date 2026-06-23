class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>last_seen;

        int left=0;
        int max_len=0;

        for(int right=0;right<s.length();right++)
        {
            char current_char=s[right];

            if(last_seen.find(current_char)!=last_seen.end())
            {
                left=max(left,last_seen[current_char]+1);
            }
            last_seen[current_char]=right;

            int current_window_length=right-left+1;
            max_len=max(max_len,current_window_length);
        }

        return max_len;
    }
};