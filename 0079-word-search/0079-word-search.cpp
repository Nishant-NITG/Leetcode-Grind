class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Try starting from every cell
        // The word could begin anywhere on the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;  // Found the word starting from this cell
                }
            }
        }
        return false;  // Word not found anywhere
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // BASE CASE 1: We've found all characters of the word
        // This must be checked FIRST
        if (index == word.length()) {
            return true;
        }
        
        // PRUNING CASE 1: Out of bounds
        // We can't go outside the grid
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        
        // PRUNING CASE 2: Character mismatch
        // Current cell doesn't match the next character
        if (board[i][j] != word[index]) {
            return false;
        }
        
        // TEMPORARY MARK: Reserve this cell so we don't reuse it
        // We use '#' as a sentinel because it won't match any letter
        char temp = board[i][j];
        board[i][j] = '#';  // Mark as visited
        
        // EXPLORATION: Try all 4 directions
        // If any direction leads to the solution, return true
        bool found = dfs(board, word, i + 1, j, index + 1) ||  // Down
                     dfs(board, word, i - 1, j, index + 1) ||  // Up
                     dfs(board, word, i, j + 1, index + 1) ||  // Right
                     dfs(board, word, i, j - 1, index + 1);    // Left
        
        // BACKTRACK: Restore the cell so other paths can use it
        // This is crucial - without this, other branches would fail
        board[i][j] = temp;
        
        return found;
    }
};