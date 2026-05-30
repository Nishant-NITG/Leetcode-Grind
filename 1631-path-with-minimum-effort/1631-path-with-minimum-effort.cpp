class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> effort(
            rows,
            vector<int>(cols, INT_MAX)
        );

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        effort[0][0] = 0;

        pq.push({0,{0,0}});

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currEffort = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if(row == rows-1 && col == cols-1)
                return currEffort;

            for(int i=0;i<4;i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr>=0 && nc>=0 &&
                   nr<rows && nc<cols)
                {
                    int edgeWeight =
                    abs(
                        heights[row][col]
                        -
                        heights[nr][nc]
                    );

                    int newEffort =
                    max(currEffort,
                        edgeWeight);

                    if(newEffort < effort[nr][nc])
                    {
                        effort[nr][nc] =
                        newEffort;

                        pq.push(
                            {
                                newEffort,
                                {nr,nc}
                            }
                        );
                    }
                }
            }
        }

        return 0;
    }
};