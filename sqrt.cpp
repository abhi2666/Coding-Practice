// Approach --> A simple binary search type should be used to solve this
/*
from 1 to n we will find mid and will check if mid * mid != n then move low 
or high based on the value of mid*mid.
*/

class Solution {
public:
    int mySqrt(int x) {
        // find the sqrt of number without built-in function
        int low = 1, high = x, int mid;
        while(low <= high)
        {
            mid = low + (high - low)/2;
            int val = mid*mid;
            if(val == x) return val;
            else if(val > x) high = mid-1;
            else low = mid + 1;
        }
        return mid;
    }
};