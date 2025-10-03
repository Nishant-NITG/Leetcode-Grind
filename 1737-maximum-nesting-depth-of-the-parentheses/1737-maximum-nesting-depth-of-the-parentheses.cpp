class Solution {
public:
    int maxDepth(string s) {
        int depth=0,maxd=0;

        for(char c:s)
        {
            if(c=='(')
            {
                depth++;
                maxd=max(maxd,depth);
            }

            else if(c==')')
            {
                depth--;
            }
        }

        return maxd;
    }
};