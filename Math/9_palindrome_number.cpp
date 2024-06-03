class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;

        long long int reverse = 0, temp = x;
        while(temp > 0) {
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }

        return reverse == x;
    }
};