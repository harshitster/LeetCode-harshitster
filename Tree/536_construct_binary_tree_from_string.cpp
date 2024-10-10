class Solution {
public:
    TreeNode* str2tree(string s) {
        stack<TreeNode*> st;
        int num = 0;
        bool isNegative = false;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (c == '(') {
                continue;
            } else if (c == ')') {
                TreeNode* child = st.top();
                st.pop();
                TreeNode* node = st.top();
                
                if (node->left == nullptr) {
                    node->left = child;
                } else {
                    node->right = child;
                }
            } else if (c == '-') {
                isNegative = true;
            } else if (isdigit(c)) {
                num = num * 10 + (c - '0');
                
                if (i + 1 == s.length() || !isdigit(s[i + 1])) {
                    if (isNegative) {
                        num = -num;
                        isNegative = false;
                    }
                    TreeNode* node = new TreeNode(num);
                    st.push(node);
                    num = 0;
                }
            }
        }
        
        return s.empty() ? nullptr : st.top();
    }
};