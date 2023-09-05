/*
Given a linked list, create a deep copy of it means ditto copy.
each node also have a random pointer which points to some randon node in the list
even null also.

*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // first create the copy list nodes and attach them in between each nodes
        ode *temp = head;
        // step 1
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        // step 2
        Node *itr = head;
        while (itr != NULL)
        {
            if (itr->random != NULL)
                itr->next->random = itr->random->next;
            itr = itr->next->next;
        }
        // step 3
        Node *dummy = new Node(0);
        itr = head;
        temp = dummy;
        Node *fast;
        while (itr != NULL)
        {
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
    }
};