class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
                
        node.end = True
        
    def starts_with(self, word):
        node = self.root
        prefix = ''
        
        for c in word:
            if c not in node.children:
                return None
            node = node.children[c]
            prefix += c
            if node.end:
                return prefix
            
        return None

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        prefix_trie = Trie()
        for word in dictionary:
            prefix_trie.insert(word)
            
        words = sentence.split(' ')
        for i in range(len(words)):
            val = prefix_trie.starts_with(words[i])
            if val is not None:
                words[i] = val
                
        return " ".join(words)