class Solution {
    private:
        static bool compare(int a, int b) {
            string sum1 = to_string(a) + to_string(b);
            string sum2 = to_string(b) + to_string(a);
            return sum1 > sum2;
        }
    public: 
        string largestNumber(vector<int>& nums) {
            sort(nums.begin(), nums.end(), compare);
            string out = "";
    
            for(int num: nums) {
                out += to_string(num);
            }
    
            if(out[0] == '0') return "0";
            else return out; 
        }
    };

// revised - 02/25/2025