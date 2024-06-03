class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;

        for(int i = 0; i < nums.size(); i += 1) {
            if(hashmap.find(nums[i]) == hashmap.end()) hashmap[nums[i]] = i;
            else {
                if(i - hashmap[nums[i]] <= k) return true;
                hashmap[nums[i]] = i;
            }
        }

        return false;
    }
};