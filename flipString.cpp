// Input: s = "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.

class Solution
{
public:
    
    int minFlipsMonoIncr(string s)
    {
        int flip = 0, countOnes = 0;
        for(auto ch : s)
        {
            if(ch == '1')
            {
                countOnes++;
            }
            else{
                flip++;
            }

            flip = min(flip, countOnes);
        }

        return flip;

    }
};