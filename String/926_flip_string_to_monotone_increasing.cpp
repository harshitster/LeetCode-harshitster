class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0, ones = 0;
        for(char c: s) {
            if(c == '1') ones += 1;
            else res = min(res + 1, ones); 
        }

        return res;
    }
};