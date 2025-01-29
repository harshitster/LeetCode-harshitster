class Solution {
private:
    int helper(int n) {
        int s = 0;
        while(n > 0) {
            s += pow(n % 10, 2);
            n /= 10;
        }

        return s;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = helper(n);

        while(slow != fast && fast != 1) {
            slow = helper(slow);
            fast = helper(helper(fast));
        }

        return fast == 1;
    }
};

// revised - 01/27/2025