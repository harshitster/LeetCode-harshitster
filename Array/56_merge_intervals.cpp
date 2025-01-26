class Solution {
private:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int left = 0, right = 1;
        int n = intervals.size();

        while(right < n) {
            int size = n;
            while(right < n && intervals[left][1] >= intervals[right][0]) {
                intervals[left][1] = max(intervals[left][1], intervals[right][1]);
                intervals.erase(intervals.begin() + right);
                n -= 1;
            }
            if(size == n) {
                left += 1;
                right += 1;
            }
        }

        return intervals;
    }
};

// revised - 01/25/2025