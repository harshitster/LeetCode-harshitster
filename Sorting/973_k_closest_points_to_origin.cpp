class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, pair<int, int>>> h;
        vector<vector<int>> res;

        for (vector<int>& v : points) {
            double distance = sqrt(pow(v[0], 2) + pow(v[1], 2)); 
            h.push_back({distance, {v[0], v[1]}});
        }

        make_heap(h.begin(), h.end(), greater<pair<double, pair<int, int>>>());
        for(int i = 0; i < k; i += 1) {
            pop_heap(h.begin(), h.end(), greater<pair<double, pair<int, int>>>());
            res.push_back({h.back().second.first, h.back().second.second});
            h.pop_back();
        }

        return res;
    }
};