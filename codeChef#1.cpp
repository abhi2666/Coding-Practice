// finding the repeating characters in all the strings 
// can be done with set and map

#include<bits/stdc++.h>
using namespace std;

int main() {
	
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<char, int>mp;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            string str;
            cin>>str;
            unordered_set<char>st(str.begin(), str.end());
            // only unique characters will be left
            for(auto ele : st){
                mp[ele]++;
            }

            for(auto it : mp){
                if(it.second == n) cnt++;
            }
            
        }
        cout<<cnt<<endl;
    
    }
	return 0;
}
