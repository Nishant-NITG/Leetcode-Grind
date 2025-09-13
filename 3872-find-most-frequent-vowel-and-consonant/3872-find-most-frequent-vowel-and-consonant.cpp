class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>fre(26,0);

        for(char c:s)
        {
            fre[c-'a']++;
        }

        string vowels="aeiou";

        int cmax=0;
        int vmax=0;

        for(int i=0;i<26;i++)
        {
            char c='a'+i;
            int f=fre[i];

            if(vowels.find(c)!=string::npos)
            {
                vmax = max(vmax, f);
            }
            else{
                cmax = max(cmax, f);
            }
        }

        return vmax+cmax;
    }
};