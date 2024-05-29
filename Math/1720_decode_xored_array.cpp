class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);

        for(int i = 0, prev = first; i < encoded.size(); i += 1) {
            prev = prev ^ encoded[i];
            res.push_back(prev);
        }

        return res;
    }
};