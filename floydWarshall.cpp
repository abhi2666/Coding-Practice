/*
To find the shortest distance from every one node to every other node.
For this purpose we will use adjacency matrix 
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){
	    // adjusting the matrix
        int n = mat.size();
        // adjusting the matrix by replacing -1 with 1e9
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) mat[i][j] = 0; // distance from i to i will always be zero until there is
                // a negative cycle.
                if(mat[i][j] == -1) mat[i][j] = 1e6;

            }
        }

        // apply Floyd Warshall
        for(int k = 0; k  <n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    // min(distance from i to j, distance from i to j via k)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        /*
        for(int i = 0 to n)
        {
            if(mat[i][j] < 0) // negative cycle
        }
        */

        // at last replace the 1e6 with their original value if there is any left
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1e6) mat[i][j] = -1;
            }
        }
	}
};