/*

The land cells present in the boundary cannot be counted in the answer as we will walk off
the boundary of the grid. Also, land cells connected to the boundary land cell can never
be the answer. 

The intuition is that we need to figure out the boundary land cells, go through their
connected land cells and mark them as visited. The sum of all the remaining land cells
will be the answer.

*/

/*

- For BFS traversal, we need a queue data structure and a visited array. Create a 
  corresponding visited array. 
- Push the coordinates of boundary nodes in the queue and mark them as visited.
- Start the BFS traversal, pop out an element from the queue every time and travel
  to all its unvisited neighboring land cells in the 4 directions. For every 
  unvisited node, push it {row, col} into the Q and mark it as visited to avoid
  multiple traversals in the future. 
- Repeat the steps until the queue becomes empty. When all the boundaries are 
  traversed and corresponding sets of 1s are marked as visited, use a counter variable
  to count the number of remaining unvisited land cells. 
- Return the value of the counter as it indicates the number of land cells that 
  cannot cross the boundary.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q; 
        int n = grid.size(); 
        int m = grid[0].size(); 
        int vis[n][m] = {0}; 
        // traverse boundary elements
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue
                    if(grid[i][j] == 1) {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            // traverses all 4 directions
            for(int i = 0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                // check for valid coordinates and for land cell
                if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; 
                }
            }
            
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }
};

int main() {
    
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
        
    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;

}
