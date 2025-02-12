class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> map;
    
            for(int i = 0; i < nums.size(); i += 1) {
                int remainder = target - nums[i];
                if(map.find(nums[i]) != map.end()) return {map[nums[i]], i};
                map[remainder] = i;
            }
    
            return {};
        }
    };

// revised - 02/11/2025