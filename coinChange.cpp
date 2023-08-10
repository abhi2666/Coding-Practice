class Solution {
  public:
    int getCoins(int idx, int coins[], int n, int sum)
    {
        if(sum == 0) return 1;
        if(idx < 0) return 0;

        // for each element you can pick it multiple times
        for(int i = idx; i < n; i++)
        {
            return getCoins(i, coins, n, sum-coins[i]) + getCoins(i+1, coins, sum);
        }

    }

    long long int count(int coins[], int N, int sum) {

        return getCoins(0, coins, N, sum);
    }
};


ListNode* newNode = new ListNode(List1->val);
p->next = newNode;
p = newNode;