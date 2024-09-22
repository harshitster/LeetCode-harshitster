class Solution:
    def minSwaps(self, data: List[int]) -> int:
        ones = 0
        for num in data:
            if num == 1:
                ones += 1

        if ones <= 1:
            return 0

        swaps, left = 0, 0 
        min_swaps = float("inf")
        for right in range(len(data)):
            while ones == 0:
                if data[left] == 0:
                    swaps -= 1
                ones += 1
                left += 1

            if data[right] == 0:
                swaps += 1
            ones -= 1

            if ones == 0:
                min_swaps = min(min_swaps, swaps)

        return min_swaps