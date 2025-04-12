/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* slowPointer = head;
       ListNode* fastPointer = head; 

       while(fastPointer && fastPointer->next) { // loop until fast pointer reaches the end of the list
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        if(slowPointer == fastPointer) { // if both pointer meet at the same node, there is a cycle
        // If the fast pointer reaches the end of the list, there is no cycle
            return true;
        }
      }
    return false;
    }
};