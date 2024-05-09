class Solution {
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* curr1 = list1,* curr2 = list2,* prev = nullptr;
        
        while(curr1 && curr2) {
            if(curr1 -> val > curr2 -> val) {
                if(prev == nullptr) {
                    list1 = curr2;
                    prev = curr2;
                    curr2 = curr2 -> next;
                    prev -> next = curr1;
                } else {
                    prev -> next = curr2;
                    curr2 = curr2 -> next;
                    prev -> next -> next = curr1;
                    prev = prev -> next;
                }
            } else {
                prev = curr1;
                curr1 = curr1 -> next;
            }
        }

        if(curr2) {
            prev -> next = curr2;
        }

        return list1;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0) return nullptr;
        
        for(int i = 1; i < size; i += 1) {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }

        return lists[0];
    }
};