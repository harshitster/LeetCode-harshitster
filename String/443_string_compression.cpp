class Solution {
private:
    int writeGroup(vector<char>& chars, int index, char c, int count) {
        chars[index++] = c;
        if(count > 1) {
            string count_str = to_string(count);
            for(char digit: count_str) {
                chars[index++] = digit;
            }
        }
        return index;
    }
    
public:
    int compress(vector<char>& chars) {
        char prev = chars[0];
        int count = 0;
        int index = 0;

        for(char c: chars) {
            if(c != prev) {
                index = writeGroup(chars, index, prev, count);
                prev = c;
                count = 1;
            } else {
                count += 1;
            }
        }

        index = writeGroup(chars, index, prev, count);
        return index;
    }
};