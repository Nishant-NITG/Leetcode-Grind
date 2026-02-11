class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        bool zerofirstrow=false;
        bool zerofirstcol=false;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0) zerofirstrow=true;
                    if(j==0) zerofirstcol=true;
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        if(zerofirstrow)
        {
           
            
                for(int j=0;j<cols;j++)
                {
                    matrix[0][j]=0;
                }
            
        }
        if(zerofirstcol)
        {
           
            
                for(int i=0;i<rows;i++)
                {
                    matrix[i][0]=0;
                }
            
        }




    }
};