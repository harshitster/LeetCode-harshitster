class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        path += '/';
        
        string file = "";
        for (char c : path) {
            if (c == '/') {
                if (file.empty()) {
                    continue;
                } else if (file == ".") {
                    // Do nothing
                } else if (file == "..") {
                    if (!stack.empty()) {
                        stack.pop_back();
                    }
                } else {
                    stack.push_back(file);
                }
                file = "";
            } else {
                file += c;
            }
        }
        
        string res = "";
        for (const string& dir : stack) {
            res += "/" + dir;
        }
        
        return res.empty() ? "/" : res;
    }
};