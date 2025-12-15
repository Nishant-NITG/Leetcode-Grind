class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        for(char c:num)
        {
            while(!st.empty() && k>0 && st.top()>c)
            {
                st.pop();
                k--;
            }

            st.push(c);
        }

        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }

        string result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();

        }
        reverse(result.begin(),result.end());

        int idx=0;
        while(idx<result.size() && result[idx]=='0')
        {
            idx++;
        }

        result=result.substr(idx);

        return result.empty()?"0":result;
    }
};