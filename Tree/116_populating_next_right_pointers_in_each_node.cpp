/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void helper(Node* left, Node* right) {
        if(left == nullptr && right == nullptr) return;

        left -> next = right;
        right -> next = nullptr;

        helper(left -> left, left -> right);
        helper(left -> right, right -> left);
        helper(right -> left, right -> right);
    }
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        root -> next = nullptr;

        helper(root -> left, root -> right);
        return root;
    }
};

// Revised - 01/16/2025