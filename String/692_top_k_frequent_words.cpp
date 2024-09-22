class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        vector<pair<int, string>> h;
        vector<string> result;

        for(string& s: words) {
            map[s] += 1;
        }

        for(auto& p: map) {
            h.push_back({-p.second, p.first});
        }

        make_heap(h.begin(), h.end(), greater<pair<int, string>>());
        for(int i = 0; i < k; i += 1) {
            pop_heap(h.begin(), h.end(), greater<pair<int, string>>());
            result.push_back(h.back().second);
            h.pop_back();
        }

        return result;
    }
};