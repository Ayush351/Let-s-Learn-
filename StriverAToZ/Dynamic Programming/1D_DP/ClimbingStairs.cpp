/*
Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb
 to the “Nth” stair. At a time we can climb either one or two steps. 
 We need to return the total number of distinct ways to reach from 0th to Nth stair.
*/


#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

int memo(int ind,vector<int>&dp)
{
    if(dp[ind] != -1)
    return dp[ind];

    if(ind<=1)
    return 1;

    int left = memo(ind-1,dp);
    int right  = memo(ind-2,dp);

    return dp[ind] =  right + left;
    // TC : O(N) -> visiting all the index
    // SC : O(N) -> extra vector
}

int tabu(int ind,vector<int>&dp)
{
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i<=ind;i++) 
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[ind];
    // TC : O(N) -> visiting all the index
    // SC : O(N) -> extra vector
}

int space_opti(int N)
{

    int prev1 = 1;
    int prev2 = 1;

    for(int i = 2;i<=N;i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
    // TC : O(N) -> visiting all the index
    // SC : O(1) -> Only two variables...
}

void solve()
{
    cin>>N;
    vector<int>dp(N+1,-1);
    //cout<<memo(N,dp)<<endl;
    //cout<< tabu(N,dp)<<endl;
     cout<<space_opti(N)<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    cin  >> T;
    while (T--)
        solve();
}