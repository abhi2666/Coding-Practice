/*
Input : arr[ ] = {1, 0, 1, 0, 1}
Output : 1
Explanation:
Only 1 swap is required to group all 1's together.
Swapping index 1 and 4 will give arr[] = {1, 1, 1, 0, 0}.

To group all 1's together we can define a window size equal to that of count(1 in array)
and then will slide the window from start to end and from all windows will capture the one
with the least no. of zeroes and will return it.
*/
// we will move the window and will check for zeroes in each windows
// a mini variable will be used in order to keep track of zeroes that
// we will have to replace in order to get all ones.

int minSwaps(int arr[], int n)
{
    int totalOnes = 0;
    for (int i = 0; i < n; i++)
    {
        totalOnes++;
    }

    if (totalOnes == 0)
        return -1; // there is no ones so we are already fucked
    if (totalOnes == n)
        return 0; // all elements are one so we don't have to do shit

    int i = 0, j = 0, ans = INT_MAX, zeroes = 0;
    while (j < n)
    {
        if (j - i < totalOnes - 1)
        {
            // means you can add more elements in window
            if (arr[j] == 0)
                zeroes++;
            j++;
        }
        else if (j - i == totalOnes - 1)
        {
            // can't pick more elements
            if (arr[j] == 0)
                zeroes++;
            ans = min(ans, zeroes);
            i++;
            if (arr[i - 1] == 0)
                zeroes--;
            j++;
        }
    }
    return ans;
}