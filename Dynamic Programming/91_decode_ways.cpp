class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        
        int one = 1, two = 1;

        for(int i = 2; i <= s.size(); i += 1) {
            int temp = two;
            if(s[i - 1] == '0') two = 0;
            
            int two_digit = stoi(s.substr(i - 2, 2));
            if(two_digit >= 10 && two_digit <= 26) two += one;
            
            one = temp;
        }

        return two;
    }
};