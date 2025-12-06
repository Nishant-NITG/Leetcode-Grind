class Solution {
public:
    vector<int> buildlps(const string &pat)
    {
        int n = pat.size();
        vector<int> lps(n, 0);
        int pre = 0;
        int suf = 1;

        while (suf < n)
        {
            if (pat[pre] == pat[suf])
            {
                pre++;
                lps[suf] = pre;
                suf++;
            }
            else
            {
                if (pre != 0)
                {
                    pre = lps[pre - 1];
                }
                else
                {
                    lps[suf] = 0;
                    suf++;
                }
            }
        }
        return lps;
    }



    string longestPrefix(string s) {
        vector<int> lps = buildlps(s);

        int longestPreSuf = lps.back();

        return (longestPreSuf!=0)? s.substr(0,longestPreSuf):"";
    }
};