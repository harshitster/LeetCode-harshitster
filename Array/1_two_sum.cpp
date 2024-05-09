class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for(int i = 0; i < nums.size(); i += 1) {
            if(hashmap.find(nums[i]) != hashmap.end()) 
                return {hashmap[nums[i]], i};
            else
                hashmap[target - nums[i]] = i;
        }

        return {};
    }
};