class Solution {
public:
    bool isHappy(int n) {
        int temp = n;
        int newNum = 0;
        while(true)
        {
            temp = newNum;
            int check = temp;
            newNum = 0;
            while(temp > 0)
            {
                int dig = temp%10;
                newNum += (dig*dig);
                temp /= 10;
            }

            if(newNum == 1) return true;   
            if(temp == check) return false;
        }
        
    }
};