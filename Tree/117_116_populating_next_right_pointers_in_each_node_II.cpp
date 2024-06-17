class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            Node* prev = nullptr;

            for(int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();

                if(prev != nullptr) {
                    prev->next = node;
                }
                prev = node;

                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
            prev->next = nullptr;
        }
        return root;
    }
};