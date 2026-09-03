class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        result = []
        depth = 0
        
        for c in s:
            if c == '(':
                depth += 1
                if depth > 1:  
                    result.append(c)
            else: 
                depth -= 1
                if depth > 0:  
                    result.append(c)
        
        return ''.join(result)