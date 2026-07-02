class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        int n=s.length();
        int left=0;
        int right=0;
        int i=0;

        while(i<n)
        {
            while(i<n && s[i]==' ')
            {
                i++;
            }

            if(i>=n) break;

            while(i<n && s[i]!=' ')
            {
                s[left++]=s[i++];
            }

            reverse(s.begin()+right,s.begin()+left);

            s[left++]=' ';
            right=left;
        }
        s.resize(left-1);
        return s;
        
    }
};