class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        st = set()
        left, max_sum = 0, 0
        curr_sum = 0

        for right in range(len(nums)):
            while left < right and ((right - left + 1) > k or nums[right] in st):
                curr_sum -= nums[left]
                st.remove(nums[left])
                left += 1

            curr_sum += nums[right]
            st.add(nums[right])
            
            if (right - left + 1) == k:
                max_sum = max(max_sum, curr_sum)

        return max_sum