/*
Problem Statement:

Given a number of stairs and a frog, the frog wants to climb from the 0th 
stair to the (N-1)th stair. At a time the frog can climb either one or two steps.
A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, 
the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the
absolute difference. We need to return the minimum energy that can be used by the
frog to jump from stair 0 to stair N-1.
*/


#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

int memo(int ind,vector<int>&dp,vector<int>&arr)
{
    if(ind == 0) return 0;

    if(dp[ind] != -1)
    return dp[ind];


    int jumpOneStep = memo(ind - 1,dp,arr) + abs(arr[ind]  - arr[ind - 1]);
    int jumpTwoStep = INT_MAX;
    if(ind - 2>=0)
    jumpTwoStep = memo(ind - 2,dp,arr) + abs(arr[ind]  - arr[ind - 2]);
    
    return dp[ind] = min(jumpOneStep,jumpTwoStep);
    // TC : O(N) -> visiting all the index
    // SC : O(N) -> Additional vector + Recursion stack
}

int tabu(int N, vector<int>&dp,vector<int>&arr)
{
    dp[0] = 0;

    for(int  i = 1;i<N;i++)
    {
        int JumpOneStep = dp[i-1] + abs(arr[i] - arr[i-1]);
        int  JumpTwoStep = INT_MAX;
        if(i > 1)
        JumpTwoStep = dp[i-2] + abs(arr[i] - arr[i-2]);

        dp[i] = min(JumpOneStep,JumpTwoStep);
    }
    return dp[N - 1];
    // TC : O(N) -> visiting all the index
    // SC : O(N) -> Additional vector...
}

int space_opti (int N,vector<int>&dp,vector<int>&arr)
{
    int prev1 = 0;
    int prev2 = -1;

    for(int  i =1;i<N;i++)
    {
        int JumpOneStep = prev1 + abs(arr[i] - arr[i-1]);
        int  JumpTwoStep = INT_MAX;
        if(i > 1)
        JumpTwoStep = prev2 + abs(arr[i] - arr[i-2]);

        dp[i] = min(JumpOneStep,JumpTwoStep);

        prev2 = prev1;
        prev1 = dp[i];

    }
    return prev1;
    // TC : O(N) -> visiting all the index
    // SC : O(1) -> Only two variables...
}

void solve()
{
    cin>>N;
    vector<int>arr(N);
    for (int i = 0; i < (int)N; i++)
    {
        cin >> arr[i];
    }    
    vector<int>dp(N,-1);
    cout<<memo(N-1,dp,arr)<<endl;
    cout<<tabu(N,dp,arr)<<endl;
    cout<<space_opti(N,dp,arr)<<endl;
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