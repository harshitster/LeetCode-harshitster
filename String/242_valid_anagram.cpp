class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(auto c: s) {
            if(map.find(c) == map.end()) map[c] = 0;
            map[c] += 1;
        }

        for(auto c: t) {
            if(map.find(c) != map.end()) {
                map[c] -= 1;
                if(map[c] == 0) map.erase(c);
            } else return false;
        }

        return map.empty();
    }
};