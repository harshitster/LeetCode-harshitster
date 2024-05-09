class Solution {
private:
    TreeNode* helper(ListNode* head, ListNode* end) {
        if(head == end) return nullptr;

        ListNode *fast = head, *slow = head;

        while(fast != end && fast -> next != end) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        TreeNode* root = new TreeNode(slow -> val);
        root -> left = helper(head, slow);
        root -> right = helper(slow -> next, end);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }
};