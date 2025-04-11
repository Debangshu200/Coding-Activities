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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(); // taking a dummyHead
        ListNode* current = dummyHead; // asssigning current to Dummy head

        while(list1 && list2) { // we are checking till two list have elements or one list has more element than other
          if(list1->val < list2->val) { // if list1 < list2 value, then assign it to the merged list
            current->next = list1;
            list1 = list1->next;
          } else { // if the elements are equal in bothe the part, then we will insert list element, we can aslo implement the conditioin in list1
            current->next = list2;
            list2 = list2->next;
          }
          current = current->next; // After all the checks assign the curren to current->next
        }
        current->next = list1 ? list1 : list2; // we are checking if one of the list has remaining element, then we can insert the remaining elements to the merged list

        return dummyHead->next;
    }
};