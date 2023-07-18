#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<string>>vect;
    vector<string>ans;
    ans.push_back("hello");
    ans.push_back("world");
    vect.push_back(ans);
    cout<<ans[1][1]<<endl;
    cout<<"hello"<<endl;
    return 0;
}