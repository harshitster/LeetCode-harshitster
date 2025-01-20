class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map;
        for(char c: s) {
            if(map.find(c) == map.end()) map[c] = 1;
            else map[c] += 1;
        }

        for(char c: t) {
            if(map.find(c) == map.end() || map[c] == 0) {
                return c;
            } else map[c] -= 1;
        }

        return '@';
    }
};