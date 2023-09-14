/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Approach --> same as the reverse list method but placement of pointers will be 
different.
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head || left == right) return head;
        ListNode* prev = head;
        for(int i = 1; i < left; i++)
        {
            prev = prev->next;
        }
        ListNode* tail = prev->next; // this tail will be used to connect to right+1 
        // and further element 

    }
};