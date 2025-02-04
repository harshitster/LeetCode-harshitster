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

        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        m, n = len(board), len(board[0])
        out = []

        def dfs(i, j, node):
            if node.word:
                out.append(node.word)

                curr = root
                for char in node.word:
                    curr = curr.children[char]
                    curr.refs -= 1

                node.word = None

            if i < 0 or i >= m or j < 0 or j >= n:
                return

            char = board[i][j]
            if char not in node.children or node.children[char].refs == 0:
                return 

            board[i][j] = '#'
            for ni, nj in directions:
                dfs(i + ni, j + nj, node.children[char])
            board[i][j] = char

        for i in range(m):
            for j in range(n):
                if board[i][j] in root.children:
                    dfs(i, j, root)
        
        return out
    
# revised - 02/03/2025