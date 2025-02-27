class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        st = {'a', 'e', 'i', 'o', 'u'}
        max_count, count = 0, 0

        for right in range(len(s)):
            if s[right] in st:
                count += 1

            max_count = max(max_count, count)

            if right + 1 >= k:
                if s[right + 1 - k] in st:
                    count -= 1

        return max_count     