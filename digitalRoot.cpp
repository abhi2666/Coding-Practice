/*
Input 1:
A = 99

Output 1:
9

Explanation 1:
99 -> 9+9 = 18 -> 1+8 = 9
*/

int Solution::solve(int A) {
    int ans = 0, sum = 0;
    while(A >= 10)
    {
        int num = A;
        sum = 0;
        while(num){
            sum += (num%10);
            num /= 10;
        }
        A = sum;
    }
    return A;
}
