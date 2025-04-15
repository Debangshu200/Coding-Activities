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
public:
    void reorderList(ListNode* head) {
        if(!head || !(head->next) || !(head->next->next)) {
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        
        ListNode* prev = nullptr;
        while(secondHalf) {
            ListNode* temp = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = temp;
        }

        ListNode* firstHalf = head;
        ListNode* secondHalfHead = prev;
        while(secondHalfHead) {
            ListNode* temp = secondHalfHead->next;
            secondHalfHead->next = firstHalf->next;
            firstHalf->next = secondHalfHead;

            firstHalf = secondHalfHead->next;
            secondHalfHead = temp;
        }
    }
};