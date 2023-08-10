class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        if (head == NULL)
            return head;
        
        int count = 0;
        while(temp)
        {
            temp = temp->next;
            count++;
        }

        count -= n;
        temp = head;
        while(count--) temp = temp->next;
        temp->next = temp->next->next;
        return head;
    }
};