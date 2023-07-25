class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        // count positive and count negatives
        // before zero and after zero count the len and return the max length
        int posLen = 0, negLen = 0;
        int ans = 0, result = 0, negFlag = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                posLen++;
            else if (nums[i] < 0)
            {
                if(negFlag == 0){
                    negFlag = i;
                }
                negLen++;
            }
                
            else if(nums[i] == 0)
            {
                // if its zero
                ans += posLen;
                if (negLen % 2 == 0)
                {
                    ans += negLen;
                }
                else
                {
                    negLen--;
                    if(negLen == 0){
                        // from this negative element till 0 exclude all
                        ans -= ((i - negFlag)-1);
                    }
                }
                result = max(ans, result);
                posLen = 0;
                negLen = 0;
                ans = 0;
                negFlag = 0;
            }
        }
        // if no zero came
        ans += posLen;
        if (negLen % 2 == 0)
        {
            ans += negLen;
        }
        else
        {
            ans += (negLen - 1);
        }
        result = max(ans, result);
        return result;
    }
};