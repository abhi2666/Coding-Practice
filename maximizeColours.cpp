#include <iostream>
using namespace std;

int main() {
	
    int t;
    cin>>t;
    while(t--)
    {
        int c = 0;
        int x, y, z;
        cin>>x>>y>>z;
        
        // base case
        if(x == 1 && y == 1 && z == 1 || x == 0 && y == 0 && z == 0){
            cout<<3*x<<endl;
        }
        else{
            // if not base case
            if(x != 0)
            {
                c++;
                x--;
            }
            if(y != 0)
            {
                c++;
                y--;
            }
            if(z != 0) {
                c++;
                z--;
            }
            if(x != 0 && y != 0)
            {
                c++;
                x--;
                y--;
            }
            if(y != 0 && z != 0)
            {
                c++;
                y--;
                z--;
            }
            if(x != 0 && z != 0)
            {
                c++;
                x--;
                z--;
            }
            cout<<c<<endl;
        }


    }

	return 0;
}