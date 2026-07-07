class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        // Mapping of digits to their corresponding letters
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        string current;
        backtrack(digits, 0, current, result, mapping);
        return result;
    }
    
private:
    void backtrack(string& digits, int idx, string& current,
                   vector<string>& result, vector<string>& mapping) {
        // BASE CASE: We've processed all digits
        // The current string is a complete combination
        if (idx == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Get the letters for the current digit
        int digit = digits[idx] - '0';
        string letters = mapping[digit];
        
        // Try each possible letter for this digit
        for (char letter : letters) {
            // MAKE CHOICE: Add the letter to our current combination
            current.push_back(letter);
            
            // RECURSE: Move to the next digit
            backtrack(digits, idx + 1, current, result, mapping);
            
            // BACKTRACK: Remove the letter to try the next one
            current.pop_back();
        }
        
        // Why this works:
        // 1. For each digit, we try all possible letters
        // 2. Each recursive call handles the next digit
        // 3. When we reach the end, we have a complete combination
        // 4. This generates all combinations (product of choices)
        // 
        // Example: "23"
        // - Digit 2: try 'a', 'b', 'c'
        // - Digit 3: for each, try 'd', 'e', 'f'
        // - Total: 3 × 3 = 9 combinations
    }
};