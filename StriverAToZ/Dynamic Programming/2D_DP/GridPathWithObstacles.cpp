/*
We are given an “N*M” Maze. The maze contains some obstacles. 
A cell is ‘blockage’ in the maze if its value is -1. 0 represents non-blockage. 
There is no path possible through a blocked cell.

We need to count the total number of unique paths from the top-left corner of the 
maze to the bottom-right corner. At every cell, we can move either down or towards the right.
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

int memo(int i,int j,vector<vector<int>>&maze,vector<vector<int>>&dp)
{
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0 || maze[i][j]==-1) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];

    
    int up = memo(i-1,j,maze,dp);

   
    int left = memo(i,j-1,maze,dp);

    return dp[i][j] = left + up;

}

int tabu(int n,int m,vector<vector<int>>&maze,vector<vector<int>>&dp)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Base conditions
            if (i < 0 || j < 0 || maze[i][j] == -1) {
                dp[i][j] = 0; 
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1; 
                continue;
            }

            int up = 0;
            int left = 0;

           
            if (i > 0)
                up = dp[i - 1][j]; 
            if (j > 0)
                left = dp[i][j - 1]; 

            dp[i][j] = up + left;
        }
    }
    return dp[n - 1][m - 1];
}

int space_opti(int n,int m,vector<vector<int>>&maze)
{
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's path counts

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            // Base conditions
            if (i < 0 || j < 0 || maze[i][j] == -1) {
                temp[j] = 0; 
                continue;
            }
            if (i == 0 && j == 0) {
                temp[j] = 1; 
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = prev[j]; 
            if (j > 0)
                left = temp[j - 1]; 

           
            temp[j] = up + left;
        }
        prev = temp; 
    }

    return prev[m - 1];
}

void solve()
{
    vector<vector<int>> maze{
        {0, -1},
        {0, 0}
    };

    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    if(maze[0][0]==1 || maze[n-1][m-1]==1)
    cout<<0<<endl;
    else
    {
    cout<<memo(n-1,m-1,maze,dp)<<endl;
    cout<<tabu(n,m,maze,dp)<<endl;
    cout<<space_opti(n,m,maze)<<endl;
    }

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
        solve();
}