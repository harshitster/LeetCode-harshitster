class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        vector<pair<int, char>> heap;
        string result = "";
        int key_count = 0;

        for(char& c: s) {
            if(map.find(c) == map.end()) key_count += 1;
            map[c] += 1;
        }

        for(auto& p: map) {
            heap.push_back({-p.second, p.first});
        }

        make_heap(heap.begin(), heap.end(), greater<pair<int, char>>());
        for(int i = 0; i < key_count; i += 1) {
            pop_heap(heap.begin(), heap.end(), greater<pair<int, char>>());
            for(int j = 0; j < -heap.back().first; j += 1) {
                result += heap.back().second;
            }
            heap.pop_back();
        }

        return result;
    }
};