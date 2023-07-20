/*
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
*/

class Solution
{
public:
    static bool compareSecondValue(const std::vector<int> &row1, const std::vector<int> &row2)
    {
        return row1[1] > row2[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int sum = 0;
        sort(boxTypes.begin(), boxTypes.end(), compareSecondValue);
        
        int i = 0;
        while(truckSize > 0 && i < boxTypes.size())
        {
            if(boxTypes[i][0] < truckSize)
            {
                sum += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                sum += boxTypes[i][1]*truckSize;
                truckSize = 0;
            }
            i++;
        }   
        return sum;
    }
    
};
