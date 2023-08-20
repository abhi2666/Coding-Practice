#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i = 0, j = 0;
        while(i < s.size() || j < t.size())
        {
            if(s[i] != s[j]) return false;
        }

        if(j == t.size()) return true;
        
        return false;
    }
};

