#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int ans = 0;
        for(auto ch : str){
            if(ch >= '0' && ch <= '9'){
                ans += stoi(ch);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
