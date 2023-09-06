/*
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
*/

// will most probably work --> Memory Limit Exceeded
// class Solution {
// public:
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         vector<ListNode*>ans;
//         ListNode* temp = head;
//         int size = 0;
//         while(temp)
//         {
//             size++;
//             temp = temp->next;
//         }
//         vector<int>sizes;
//         int len = size/k;
//         int val = len;
//         while(val < size)
//         {
//             val += len;
//             sizes.push_back(len);
//         }
//         val -= len;
//         int extra = (len-val) == 0 ? 0 : (len-val);
//         int i = 0;
//         while(extra--)
//         {   
//             sizes[i] +=1;
//             i++;
//         }

//         temp = head;
//         ListNode* helper = head;
//         for(auto s : sizes)
//         {
//             s = s - 1;
//             while(s--)
//             {
//                 helper = helper->next;
//             }
//             ans.push_back(temp);
//             temp = helper->next;
//             helper->next = NULL;
//             helper = temp;
//         }
        
//         return ans;
//     }
// };

/// @brief we will use a more optimised approach to solve this problem
// In this we will not use any extra space
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int size = 0;
        ListNode* newNode = head;
        while(newNode)
        {
            size++;
            newNode = newNode->next;
        }

        int toDivideLen = size/k;
        int extraNodes = size%k //we will add nodes and will reduce its value each time

        newNode = head;
        ListNode* temp = NULL;
        while(newNode != NULL)
        {
            ans.push_back(newNode);
            for(int i = 0; i < toDivideLen + (extraNodes > 0 ? 1 : 0); i++)
            {
                temp = newNode;
                newNode = newNode->next;
            }
            
            temp->next = NULL;
            extraNodes--;
        }
        int leftNodes = k - ans.size();
        while(leftNodes--) ans.push_back({});

    }
};