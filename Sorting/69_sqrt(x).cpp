class Solution {
    public:
        int mySqrt(int x) {
            int left = 0, right = x;
            int res;
            while(left <= right) {
                long long int pivot = left + (right - left) / 2;
    
                if(pivot * pivot > x) right = pivot - 1;
                else if(pivot * pivot < x) {
                    res = pivot;
                    left = pivot + 1;
                } else return pivot;
            }
    
            return res;
        }
    };