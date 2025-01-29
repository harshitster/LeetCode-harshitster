class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None
        self.refs = 0
        
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for word in words:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
                node.refs += 1
            node.word = word
        
        m, n = len(board), len(board[0])
        result = []
        
        def dfs(i, j, node):
            if node.word:
                result.append(node.word)
                node.word = None 
                
                curr = root
                for char in result[-1]:
                    curr = curr.children[char]
                    curr.refs -= 1
            
            if i < 0 or i >= m or j < 0 or j >= n:
                return
            
            char = board[i][j]
            if char not in node.children or node.children[char].refs == 0:
                return
                
            board[i][j] = '#'
            node = node.children[char]
            
            dfs(i+1, j, node)
            dfs(i-1, j, node)
            dfs(i, j+1, node)
            dfs(i, j-1, node)
            
            board[i][j] = char
        
        for i in range(m):
            for j in range(n):
                if board[i][j] in root.children:
                    dfs(i, j, root)
        
        return result