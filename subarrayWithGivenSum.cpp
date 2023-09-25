/*
N = 5, S = 12
A[] = {1,2,3,7,5}

approach --> a sliding window approach can be used to get the subarray.
*/

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long sum = arr[0];
        int i =0, j = 0; 
        if(s == 0) return {-1};
        while(j < arr.size())
        {
            
            if(sum == s)
            {
                return {i+1, j+1};
            }
            else if(sum  > s)
            {
                sum -= arr[i];
                i++;
            }
            else{
                j++;
                sum += arr[j];
            }
        }
        return {-1};
    }
};
