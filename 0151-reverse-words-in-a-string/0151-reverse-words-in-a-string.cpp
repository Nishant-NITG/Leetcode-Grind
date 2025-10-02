class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        
        // Extract words and push to stack (automatic reversal)
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            }
        }
        
        // Handle last word
        if (!word.empty()) {
            st.push(word);
        }
        
        // Build result from stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) {
                result += " ";
            }
        }
        
        return result;
    }
};