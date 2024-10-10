class Solution:
    def reverse(self, s, left, right):
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

    def reverseWords(self, s: str) -> str:
        left, right = 0, len(s) - 1
        while left <= right and s[left] == " ":
            left += 1
        while left <= right and s[right] == " ":
            right -= 1

        sm = []
        while left <= right:
            if s[left] != " " or sm[-1] != " ":
                sm.append(s[left])
            left += 1

        left, right = 0, len(sm) - 1
        self.reverse(sm, 0, right)

        for right in range(len(sm)):
            if sm[right] == " ":
                self.reverse(sm, left, right - 1)
                left = right + 1
        self.reverse(sm, left, len(sm) - 1)

        return "".join(sm)