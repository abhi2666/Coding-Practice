/*
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

A simple BFS traversal can be applied to get the result and at the end we can check for
if there are any 1 left.
TC - O(m * n)
*/
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     bool anyOneLeft(vector<vector<int>>grid){
//         for(int i = 0; i < grid.size(); i++)
//         {
//             for(int j = 0; j < grid[i].size(); j++)
//             {
//                 if(grid[i][j] == 1) return true;
//             }
//         }
//         return false;
//     }

//     void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<int>>&grid)
//     {
//         int m = grid.size();
//         int n = grid[0].size();
//         visited[row][col] = 1;
//         queue<pair<int, int>>q;
//         q.push({row, col});
//         int dir_row[] = {-1, 0, 1, 0};
//         int dir_col[] = {0, 1, 0, -1};
//         while(!q.empty())
//         {
//             // we will find all the 1's around it and will fuck them all
//             auto val = q.front();
//             q.pop();
//             // we will now check all its neighbours that are 1 and are not yet visited
//             for(int i = 0; i < 4; i++)
//             {
//                 int rowN = val.first + dir_row[i];
//                 int colN = val.second + dir_col[i];
//                 //check if you can pick it
//                 if(rowN >= 0 && rowN < m && colN >= 0 && colN < n && grid[rowN][colN]==1 && !visited[rowN][colN]){
//                     q.push({rowN, colN});
//                     visited[rowN][colN] = 1;
//                 }
//             }

//         }
//     }

//     int orangesRotting(vector<vector<int>>& grid) {
//         int count = 0;
//         vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
//         for(int i = 0; i < grid.size(); i++)
//         {
//             for(int j = 0; j < grid[i].size(); j++)
//             {
//                 if(grid[i][j] == 2)
//                 {
//                     // you have got an potty orange start BFS
//                     bfs(i, j, visited, grid);
//                     count++;
//                 }
//             }
//         }

//         // at the end check if there is any 1 left or not
//         if(anyOneLeft(grid)) return -1;
//         else return count;
//     }
// };

// above solution has some problems with finding the right time

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        int cntOnes = 0;              // will count total 1 and will check it again after bfs is done
        queue<pair<pair<int, int>, int>> q; // {{row, col}, time}
        int visited[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    // you have got an potty orange start BFS
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else
                {
                    visited[i][j] = 0;
                }

                if (grid[i][j] == 1)
                    cntOnes++;
            }
        }

        // start bfs
        int dir_row[] = {-1, 0, 1, 0};
        int dir_col[] = {0, 1, 0, -1};
        int ones = 0, mxTime = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            mxTime = max(mxTime, t);
            for(int i = 0; i < 4; i++)
            {
                int rowN = r + dir_row[i];
                int colN = c + dir_col[i];
                if(rowN >= 0 && rowN < rows && colN >= 0 && colN < cols && visited[rowN][colN] == 0 && grid[rowN][colN] == 1){
                    //can pick the element
                    q.push({{rowN, colN}, t+1});
                    visited[rowN][colN] = 2;
                    ones++;
                }
            }
        }
        if(cntOnes == ones)
        {
            // means all the 1's are transformed to 2
            return mxTime;
        }
        else{
            return -1;
        }
    }
};