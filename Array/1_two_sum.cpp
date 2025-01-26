class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i += 1) {
            int remainder = target - nums[i];
            if(map.find(remainder) != map.end()) return {map[remainder], i};
            map[nums[i]] = i;
        }

        return {};
    }
};
    
// revised - 01/25/2025