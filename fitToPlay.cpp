#include<bits/stdc++.h>
using namespace std;

int main() {
	// simple kadane based approach should work

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        int gap = 0, val = a[0];

        for(int i = 1; i < n; i++)
        {
            if(a[i] > val)
            {
                gap = max(gap, (a[i]-val));
            }
            else{
                val = a[i]; // there is someone more smaller..it will larger gap diff
            }
        }
        
        if(gap > 0){
            cout<<gap<<endl;
        }
        else{
            cout<<"UNFIT"<<endl;
        }
    }

	return 0;
}
