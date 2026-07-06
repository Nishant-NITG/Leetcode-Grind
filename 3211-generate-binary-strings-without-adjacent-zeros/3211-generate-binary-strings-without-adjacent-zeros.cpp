class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string current;
        back(current,n,result);
        return result;
    }


public:
    void back(string& current,int n,vector<string>& result)
    {
        if(current.length()==n)
        {
            result.push_back(current);
            return;
        }

        if(current.empty() || current.back()=='1')
        {
            current.push_back('0');
            back(current,n,result);
            current.pop_back();
        }

                current.push_back('1');            // Make a choice
        back(current, n, result);     // Explore with this choice
        current.pop_back(); 


    }
};