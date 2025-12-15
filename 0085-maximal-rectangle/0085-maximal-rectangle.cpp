class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {

            // Build histogram heights for current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Largest Rectangle in Histogram
            stack<int> st;
            for (int k = 0; k <= cols; k++) {
                int currHeight = (k == cols) ? 0 : heights[k];

                while (!st.empty() && currHeight < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();

                    int right = k;
                    int left = st.empty() ? -1 : st.top();
                    int width = right - left - 1;

                    maxArea = max(maxArea, h * width);
                }
                st.push(k);
            }
        }

        return maxArea;
    }
};
