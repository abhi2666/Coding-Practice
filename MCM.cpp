/*
Matrix Chain Multiplication (based on partition dp)
Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

Approach --> for two matrix a * b & c * d where b = c --> total operations would be 
a * b * d..we will just calculate this and with every iteration will reduce the size
of partition window.
*/


// find the multiplication with the least product

class Solution{
public:

    int MCM(int i, int j, int a[])
    {
        if(i == j) return 0; // you are on the same matrix
        
        int mini = INT_MAX;
        for(int k = i; k < j - 1; k++)
        {
            int steps = a[i - 1] * a[k] * a[j] + MCM(i, k) + MCM(k + 1, j);
            mini = min(mini, steps);
        }

        return mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        return MCM(1, N-1, arr);
    }
};
