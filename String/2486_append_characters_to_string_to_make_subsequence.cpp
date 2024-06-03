class Solution {
public:
    int appendCharacters(string s, string t) {
        int idx = 0, size = t.size();

        for(int i = 0; i < s.size(); i += 1) {
            if(idx == size) return 0;

            if(s[i] == t[idx]){
                idx += 1;
            }
        }

        return size - idx;
    }
};