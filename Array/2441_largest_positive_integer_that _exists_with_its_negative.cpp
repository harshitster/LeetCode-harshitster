class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int res = -1;

        for(auto num: nums) {
            if(hashmap.find(-num) == hashmap.end()) hashmap[num] = 1;
            else res = max(res, abs(num));
        }

        return res;
    }
};