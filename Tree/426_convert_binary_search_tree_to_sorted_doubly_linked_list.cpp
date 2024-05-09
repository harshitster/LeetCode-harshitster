class Solution {
private:
    void helper(Node* root, Node** prev) {
        if(root == nullptr) return;

        helper(root -> left, prev);

        (*prev) -> right = root;
        root -> left = (*prev);
        (*prev) = root;

        helper(root -> right, prev);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;

        Node* temp = new Node(0);
        Node* prev = temp;

        helper(root, &prev);

        temp -> right -> left = prev;
        prev -> right = temp -> right;

        return prev -> right;
    }
};