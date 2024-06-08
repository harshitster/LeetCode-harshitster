class Solution:
    def heapify(self, arr, n, i):
        smallest = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < n and arr[left] < arr[smallest]:
            smallest = left
        if right < n and arr[right] < arr[smallest]:
            smallest = right

        if smallest != i:
            arr[smallest], arr[i] = arr[i], arr[smallest]
            self.heapify(arr, n, smallest)

    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n = len(hand)
        if n % groupSize != 0:
            return False
        groups = n // groupSize

        hashmap = {}
        size = 0
        for num in hand:
            if num not in hashmap:
                hashmap[num] = 1
                size += 1
            else:
                hashmap[num] += 1

        nums = list(hashmap.keys())
        for i in range(size // 2, -1, -1):
            self.heapify(nums, size, i)

        last_index = size - 1
        for _ in range(groups):
            if last_index == -1:
                return False

            num = nums[0]
            for _ in range(groupSize):
                if num not in hashmap or last_index < 0:
                    return False

                hashmap[num] -= 1
                if hashmap[num] == 0:
                    del hashmap[num]
                    nums[last_index], nums[0] = nums[0], nums[last_index]
                    self.heapify(nums, last_index, 0)
                    last_index -= 1
                    
                num += 1 

        return True
    

# Can be optimized