class Solution:
    def compress(self, chars: List[str]) -> int:
        prev, count = None, 0
        index = 0

        for c in chars:
            if prev is None:
                prev = c
                count = 1
            elif c == prev:
                count += 1
            else:
                chars[index] = prev
                index += 1
                if count != 1:
                    str_rep = str(count)
                    chars[index: index + len(str_rep)] = list(str_rep)
                    index += len(str_rep)
                prev = c
                count = 1

        chars[index] = prev
        index += 1
        if count != 1:
            str_rep = str(count)
            chars[index: index + len(str_rep)] = list(str_rep)
            index += len(str_rep)

        return index