class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: detect cycle
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        if(!fast || !fast->next)
            return NULL;

        // Step 2: find cycle start
        ListNode* ptr1 = head;
        ListNode* ptr2 = slow;

        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1;
    }
};