class Solution {
    public:
        int climbStairs(int n) {
            int one = 1, two = 1;
            for(int i = 2; i <= n; i += 1) {
                int temp = two;
                two += one;
                one = temp;
            }
            return two;
        }
    };

// revised - 02/12/2025