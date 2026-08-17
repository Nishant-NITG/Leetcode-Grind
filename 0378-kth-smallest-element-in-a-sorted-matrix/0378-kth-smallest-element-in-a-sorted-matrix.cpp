class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();

        priority_queue<vector<int>,
                        vector<vector<int>>,
                        greater<vector<int>>>minheap;

        
        for(int i=0;i<n;i++)
        {
            minheap.push({matrix[i][0],i,0});
        }

        for(int count=1;count<k;count++)
        {
            vector<int>current=minheap.top();
            minheap.pop();

            int row=current[1];
            int col=current[2];

            if(col+1<n)
            {
                minheap.push({matrix[row][col+1],row,col+1});
            }
        }
        return minheap.top()[0];


    }
};