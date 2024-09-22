class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def add(self, word):
        cur = self.root

        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]

        cur.endOfWord = True

    def search(self, word):
        def dfs(word, index, cur):
            if index == len(word):
                return cur.endOfWord

            if word[index] == '.':
                for c, trienode in cur.children.items():
                    if dfs(word, index + 1, trienode):
                        return True
            else:
                if word[index] in cur.children:
                    return dfs(word, index + 1, cur.children[word[index]])
                else:
                    return False

        return dfs(word, 0, self.root)

class WordDictionary:
    def __init__(self):
        self.trie = Trie()        

    def addWord(self, word: str) -> None:
        self.trie.add(word)

    def search(self, word: str) -> bool:
        return self.trie.search(word)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)