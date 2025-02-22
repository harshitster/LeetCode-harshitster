class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()

        min_radius = 0
        i = 0
        
        for house in houses:
            while i < len(heaters) - 1 and abs(heaters[i] - house) >= abs(heaters[i + 1] - house):
                i += 1
            
            min_radius = max(min_radius, abs(heaters[i] - house))
        
        return min_radius