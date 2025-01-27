class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;
        for(int i = 1; i < n / 2 + 1; i += 1) {
            if(n % i == 0) {
                count += 1;
                if(count == k) return i;
            }
        }
        if(count + 1 == k) return n;
        return -1;
    }
};