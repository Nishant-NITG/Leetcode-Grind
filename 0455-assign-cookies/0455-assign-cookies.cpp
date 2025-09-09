class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child=g.size();
        int parent=s.size();
        sort(g.begin(), g.end());  
        sort(s.begin(), s.end());

        vector<bool>visited(parent,false);
        int count=0;
        int i=0;
        int j=0;

        while(i<child && j<parent)
        {
            if(s[j]>=g[i])
            {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};