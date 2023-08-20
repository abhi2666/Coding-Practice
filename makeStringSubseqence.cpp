#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int diffChar = 0;
        unordered_set<int>st;
        for(int i = 0; i < str1.size(); i++)
        {
            st.insert(str1[i]);
        }
        for(char ch : str2)
        {
            if(st.find(ch) == st.end())
            {
                diffChar++;
            }
        }

        cout<<"diff char"<<diffChar<<endl;

        for(int i = 0; i < str1.size(); i++)
        {
            for(int j = 0; j < str2.size(); j++)
            {
                if((str1[i] - str2[j]%25) <= 1)
                {
                    diffChar--;
                } 
            }
            
        }
        if(diffChar == 0) return true;
        else return false;
    }
};
