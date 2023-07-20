#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>vect = {{8,0}, {1,3},{2,6},{15,18}};
    sort(vect.begin(), vect.end());
    for(int i = 0; i < vect.size(); i++)
    {
        cout<<vect[i][0]<<" "<<vect[i][1]<<endl;
    }
    return 0;
}