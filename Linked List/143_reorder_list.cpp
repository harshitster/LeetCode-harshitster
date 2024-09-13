/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr,* curr = head,* next = head -> next;

        while(next) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = next -> next;
        }
        curr -> next = prev;
        head = curr;
        return head;
    }
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return;

        ListNode* slow = head,* fast = head;
        ListNode* prev = nullptr;
        while(fast && fast -> next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = nullptr;
        slow = reverseList(slow);

        ListNode* temp1 = head,* temp2 = slow;
        prev = nullptr;
        while(temp1 && temp2) {
            ListNode* temp = temp2 -> next;
            temp2 -> next = temp1 -> next;
            temp1 -> next = temp2;

            prev = temp2;
            temp1 = temp2 -> next;
            temp2 = temp;
        }

        if(temp2) prev -> next = temp2;
    }
};