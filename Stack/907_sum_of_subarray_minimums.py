class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        res = 0
        stack = []

        for i in range(len(arr) + 1):
            while stack and (i == len(arr) or arr[stack[-1]] >= arr[i]):
                mid = stack.pop()
                left = stack[-1] if stack else -1
                right = i

                count = (mid - left) * (right - mid)
                res += count * arr[mid]

            stack.append(i)

        return res % MOD
    
# revised - 02/21/2025