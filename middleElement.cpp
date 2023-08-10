// 1 2 3 4 5 6

// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode*slow = head;
//         ListNode*fast = head;

//         while(fast != NULL || fast->next != NULL)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         return slow;
//     }
// };

#include<iostream>
using namespace std;


int main()
{
    string s = "ab2cd5";
    int sum = 0;
    for(char ch : s)
    {
        if(ch >= '0' && ch <= '1')
        {
            sum += (ch - '0');
        }
    }
    cout<<sum<<endl;
}