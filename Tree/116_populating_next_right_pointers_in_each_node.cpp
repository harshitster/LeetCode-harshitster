class Solution {
private:
    void helper(Node* p, Node* q) {
        if(p == nullptr && q == nullptr) return;

        p -> next = q;
        q -> next = nullptr;

        helper(p -> left, p -> right);
        helper(p -> right, q -> left);
        helper(q -> left, q -> right);
    }
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;

        root -> next = nullptr;
        helper(root -> left, root -> right);

        return root;
    }
};