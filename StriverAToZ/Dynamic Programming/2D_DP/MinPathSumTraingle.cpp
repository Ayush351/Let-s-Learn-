/*
We are given a Triangular matrix. We need to find the minimum path sum 
from the first row to the last row.
At every cell we can move in only two directions: either to the bottom cell (↓)
or to the bottom-right cell(↘)

*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";


int memo(int i,int j,vector<vector<int>>triangle,int n,vector<vector<int>>dp)
{
    // If the result for this cell is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If we're at the bottom row, return the value of the current cell
    if (i == n - 1)
        return triangle[i][j];

    // Calculate the sum of two possible paths: going down and going diagonally
    int down = triangle[i][j] + memo(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + memo(i + 1, j + 1, triangle, n, dp);

    // Store the minimum of the two paths in the dp table and return it
    return dp[i][j] = min(down, diagonal);
}

int tabu(vector<vector<int> > &triangle, int n) {
    // Create a 2D DP (dynamic programming) array to store minimum path sums
    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}

int space_opti(vector<vector<int>> &triangle, int n) {
    // Create two arrays to store the current and previous row values
    vector<int> front(n, 0); // Represents the previous row
    vector<int> cur(n, 0);   // Represents the current row
    
    // Initialize the front array with values from the last row of the triangle
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }
    
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            
            // Store the minimum of the two possible paths in the current row
            cur[j] = min(down, diagonal);
        }
        // Update the front array with the values from the current row
        front = cur;
    }
    
    // The front array now contains the minimum path sum from the top to the bottom of the triangle
    return front[0];
}

void solve()
{
    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    cout<<memo(0,0,triangle,n,dp)<<endl;
    cout<<tabu(triangle,n)<<endl;
    cout<<space_opti(triangle,n)<<endl;
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

        solve();
}