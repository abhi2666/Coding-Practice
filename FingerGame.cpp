class Solution
{
public:
    int fingerCount(int N)
    {
        // based on the flag we will decide which way to go
        int count = 0, finger = 0;
        bool flag = true;
        while(count != N)
        {
            count++;
            if(flag) finger++;
            else finger--;
            if(finger==1) flag = true;
            if(finger==5) flag = false;
        }
        return finger;
    }
};

