/*
Given two values M and N, which represent a matrix[M][N].
We need to find the total unique paths from the top-left cell (matrix[0][0]) 
to the rightmost cell (matrix[M-1][N-1]).
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

int memo(int i,int j,vector<vector<int>>&dp)
{
     // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;

    // If we go out of bounds or reach a blocked cell, there are no ways.
    if (i < 0 || j < 0)
        return 0;

    // If we have already computed the number of ways for this cell, return it.
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int up = memo(i-1,j,dp);
    int left = memo(i,j-1,dp);

    return dp[i][j] = up + left;
}

int tabu(int n, int m, vector<vector<int>>dp)
{
    
    for (int i = 0; i < (int)n; i++)
    {
        for (int j = 0; j < (int)m; j++)
        {
            //base case
             if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }
            int up=0 ,left=0;
            if(i > 0)
             up = dp[i-1][j];
            if(j > 0)
             left = dp[i][j-1];

            dp[i][j] = up + left;
        }    
    }    
    return dp[n-1][m-1];
}

int space_opti(int n,int m)
{
    vector<int>prev(m,0);
    for(int  i = 0;i<n;i++)
    {
        vector<int>curr_temp(m,0);
        for(int j= 0;j<m;j++)
        {
            if(i == 0 && j == 0)
            {
                curr_temp[j] = 1;
                continue;
            }
            int up = 0,left = 0;
            if(i > 0)
            up = prev[j];

            if(j> 0)
            left = curr_temp[j-1];

            curr_temp[j] = up + left; 
        }
        prev = curr_temp;
    }
    return prev[m -1];
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    cout << memo(n-1,m-1,dp)<<endl;
    cout << tabu(n,m,dp)<<endl;
    cout << space_opti(n,m)<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
   
        solve();
}