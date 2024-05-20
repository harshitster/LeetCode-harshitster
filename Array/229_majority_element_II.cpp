class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int limit = nums.size() / 3;
        std::vector<int> result;

        for (int num : nums) {
            if (hashmap.find(num) == hashmap.end()) {
                hashmap[num] = 1;
            } else {
                hashmap[num]++;
            }
        }

        for (auto& pair : hashmap) {
            if (pair.second > limit) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};