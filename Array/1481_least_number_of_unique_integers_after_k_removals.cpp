class Solution {
public:
    static bool compareByCount(pair<int,int>& a, pair<int,int>& b) {
        return a.second < b.second;
    }
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        for(int n: arr) {
            count[n]++;
        }

        vector<pair<int, int>> h;
        for(auto& pair: count) h.push_back({pair.first, pair.second});
        
        sort(h.begin(), h.end(), compareByCount);
        
        int remaining = h.size();
        for(auto& pair: h) {
            if(k >= pair.second) {
                k -= pair.second;
                pair.second = 0;
                remaining--;
            } else {
                break;
            }
        }
        
        return remaining;
    }
};