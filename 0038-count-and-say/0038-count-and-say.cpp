class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string current="1";
        for(int i=2;i<=n;i++)
        {
            current=rle(current);
        }
        return current;
    }


    private:

    string rle(const string& s)
    {
        string result="";
        int i=0;
        int n=s.length();

        while(i<n)
        {
            char currentChar=s[i];
            int count=0;

            while(i<n && s[i]==currentChar)
            {
                count++;
                i++;
            }
            result+=to_string(count)+currentChar;
        }
        return result;
        
    }
};