class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(!curr && !curr->next)
        {
            // we will smartly build new connections using old connections
            //1 -> 2 -> 3-> 4-> 5
    //    p   c

            //make connections
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            // move pointers 
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;

    }
};