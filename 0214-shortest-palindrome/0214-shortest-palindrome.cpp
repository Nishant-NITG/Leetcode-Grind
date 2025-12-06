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

    string shortestPalindrome(string s) {

        string rev = string(s.rbegin(), s.rend());

        string t = s + "#" + rev;     // FIXED: don't use keyword 'new'

        vector<int> lps = buildlps(t);

        int longestPrefixPal = lps.back();

        string suffix = s.substr(longestPrefixPal);

        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};
