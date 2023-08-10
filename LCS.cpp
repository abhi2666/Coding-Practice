class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        unordered_map<char, int>fors1;
        unordered_map<char, int>fors2;

        for(int i = 0; i < s1.size(); i++)
        {
            fors1[s1[i]] = 1;
        }
        for(int i = 0; i < s2.size(); i++)
        {
            fors2[s2[i]] = 1;
        }

        int i = 0, j = 0, count = 0;
        for(char i = 'A'; i <= 'Z'; i++)
        {
            if(fors1.find(i) != fors1.end() && fors2.find(i) != fors2.end())
            {
                count++;
            }
        }
        return count;
    }
};