class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;

        int curr_sum = 0, count = 0;
        for(int num: nums) {
            curr_sum += num;

            if(curr_sum == k) count += 1;
            if(hashmap.find(curr_sum - k) != hashmap.end()) count += hashmap[curr_sum - k];

            if(hashmap.find(curr_sum) == hashmap.end()) hashmap[curr_sum] = 1;
            else hashmap[curr_sum] += 1;
        }

        return count;
    }
};