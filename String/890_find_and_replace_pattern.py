class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        res = []
        pattern_length = len(pattern)

        for word in words:
            if len(word) != pattern_length:
                continue

            pattern_map, word_map = {}, {}
            match = True

            for i in range(pattern_length):
                if pattern[i] not in pattern_map and word[i] not in word_map:
                    pattern_map[pattern[i]] = word[i]
                    word_map[word[i]] = pattern[i]
                else:
                    if pattern[i] in pattern_map and pattern_map[pattern[i]] != word[i]:
                        match = False
                    if word[i] in word_map and word_map[word[i]] != pattern[i]:
                        match = False

                if not match:
                    break

            if match:
                res.append(word)

        return res