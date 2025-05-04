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
        // Checking 3 scenarios - the list is empty, the list has 1 node, the list has only on node - so in these three cases we don't need to reorder.
        if(!head || !(head->next) || !(head->next->next)) {
            return;
        }
        // Checking the midlle of the list , leetcode - 876
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Splitting the list into two, 
        ListNode* secondHalf = slow->next; // splitting from slow->next node
        slow->next = nullptr; // after assiging slow->next to secondHalf(reference) as new head of the second part, we added nullptr to slow->next which is our first half

        // Reversing the second half of the list , Leetcode - 206
        ListNode* prev = nullptr;
        while(secondHalf) { // while secondHalf(head) is not empty
            ListNode* temp = secondHalf->next; // here head->next assigned to temp
            secondHalf->next = prev; // head->next assigned to prev(nullptr)
            prev = secondHalf; // after that prev is assined with head
            secondHalf = temp; // head is assigned with head->next
        }

        // Strat Mergint he first and second half , Leetcode - 21
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