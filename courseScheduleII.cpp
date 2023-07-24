/*
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].



Approach --> store the elements with their frequency into the map and sort it in decreasing 
order of frequency. Then one by one pick element and put it into the vector.
If any element remain then put it also at the very end.
*/

// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int>ans;
//         if(numCourses == 1){
//             ans.push_back(0);
//             return ans;
//         }
//         if(numCourses == 2){
//             ans.push_back(prerequisites[1]);
//             ans.push_back(prerequisites[0]);
//             return ans;
//         }
//         // if not these case then we will process it 
//         map<int, int>mp; // freq and element
//         for(int i = 0; i < prerequisites.size(); i++)
//         {
//             mp[prerequisites[i][1]]++;
//         }
//     }
// };