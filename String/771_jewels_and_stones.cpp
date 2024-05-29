class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> js;

        for(char j: jewels) js.insert(j);

        int count = 0;
        for(char s: stones) {
            if(js.find(s) != js.end()) count += 1;
        }

        return count;
    }
};