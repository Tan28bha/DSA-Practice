class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;

        // STEP 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        // Important: break the first half
        slow->next = nullptr;

        while (curr != nullptr) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // prev = head of reversed second half

        // STEP 3: Merge two halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};