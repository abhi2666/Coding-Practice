/*
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

/*
we can either use DFS or BFS to traverse the matrix where starting point will be
1 only (for a 1 to be starting point, it should not be visited).
*/
class Solution
{
private:
  void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &grid)
  {
    // just traverse the elements which are 1
    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j}); 

    // we will create two arrays that will have points for the directions
    int dirRow[] = {1, -1, 0, 0};
    int dirCol[] = {0, 0, 1, -1};

    while(!q.empty())
    {
      auto indicies = q.front();
      // you will put the indicies into the queue if they are not visited yet and 
      // they are 1 (representing land)
      for(int i = 0; i < 4; i++)
      {
        int rowN = indicies.first + dirRow[i];
        int colN = indicies.second + dirCol[i];

        //check if you can pick this neighbour node or not
        if(rowN >= 0 && rowN < grid.size()  && colN >=0 && colN < grid[0].size() && grid[rowN][colN] == '1' && visited[rowN][colN] == 0){
          // implies you can pick this node
          q.push({rowN, colN});
          visited[rowN][colN] = 1;
        }
      }
    }

  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int rows = grid.size();
    int columns = grid[0].size();
    int cnt = 0;
    // 2D visited array for marking the elements
    vector<vector<int>> visited(rows, vector<int>(columns, 0));
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        // we have to find 1 and check if its not visited then perform the BFS
        if (grid[i][j] == 1 && !visited[i][j])
        {
          // you can perform the BFS on this element
          bfs(i, j, visited, grid);
          cnt++;
        }
      }
    }
    return cnt;
  }
};