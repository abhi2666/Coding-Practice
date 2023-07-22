/*
Meeting rooms 2 -> find the no. of rooms that are good enough to accomodate
all the meetings given in the interval
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int meetingRooms(vector<vector<int>>a){
        // create two vectors, for start and for end
        vector<int>start;
        vector<int>end;
        for(auto i : a)
        {
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s = 0, e = 0, roomsRequired = 0;
        while(s < start.size())
        {
            if(start[s] < end[e])
            {
                // means you will have to add a room
                roomsRequired++;
                s++;
            }
            else if(start[s] > end[e]){
                // if either start > end or start = end we just have 
                // in both cases one room will become free 
                e++;
            }
            else{
                s++;
                e++;
            }
        }
        return roomsRequired;

    }
};

int main(){
    vector<vector<int>>a = {{0, 30}, {5, 10}, {10, 20}, {20, 40}};
    Solution s;
    int result = s.meetingRooms(a);
    cout<<"total rooms--> "<<result<<endl;
    return 0;
}