class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;

        vector<int> p(n), q(n);
        p[0] = INT_MIN;
        q[n - 1] = INT_MIN;

        for(int i = 1; i < n; i += 1) p[i] = nums[i] - nums[i - 1];
        for(int i = 0; i < n - 1; i += 1) q[i] = nums[i + 1] - nums[i];

        for(int i = 0; i < n; i += 1) {
            if(p[i] > 0 && q[i] < 0) return i;
        }
        return 0;
    }
};