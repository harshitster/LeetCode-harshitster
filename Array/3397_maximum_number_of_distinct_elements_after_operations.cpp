class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int prev = INT_MIN, count = 0;
        sort(nums.begin(), nums.end());
        for(int n: nums) {
            if(prev < n - k) {
                prev = n - k;
                count += 1;
            } else if(prev < n + k) {
                prev += 1;
                count += 1;
            }
        }

        return count;
    }
};