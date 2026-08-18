class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<bool>visited(n,0);
        int province=0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                province++;
                dfs(i,isConnected,visited);
            }
        }
        return province;
    }

    void dfs(int city,vector<vector<int>>& isConnected,vector<bool>&visited){
        visited[city]=1;

        for(int j=0;j<isConnected.size();j++)
        {
            if(isConnected[city][j]==1 && !visited[j])
            {
                dfs(j,isConnected,visited);
            }
        }
    }
};