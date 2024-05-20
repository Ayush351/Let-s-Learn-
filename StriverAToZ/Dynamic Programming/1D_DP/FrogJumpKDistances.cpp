/*
In this question, the frog is allowed to jump up to ‘K’ steps at a time.
 If K=4, the frog can jump 1,2,3, or 4 steps at every index.
*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

int memo(int ind,vector<int>&dp,vector<int>&arr,int K)
{
    if(ind == 0) return 0;
    if(dp[ind] != -1 ) return dp[ind];
    int minsteps = INT_MAX;
    for(int  i = 1;i<=K;i++)
    {
        if(ind - i>= 0)
        {
            int jumps = memo(ind - i,dp,arr,K) + abs(arr[ind] - arr[ind - i]);
            minsteps = min(minsteps,jumps);
        }
    }
    return dp[ind] = minsteps;
    // TC : O(N) -> visiting all the index
    // SC : O(N) -> Additional vector + Recursion stack
}

int tabu(int N,vector<int>&dp,vector<int>&arr,int K)
{
    dp[0] = 0;
    for(int i = 1;i<N;i++)
    {
        int minsteps = INT_MAX;
        for(int j = 1;j<=K;j++)
        {
            if(i - j>=0)
            {
                int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                minsteps = min(minsteps, jump);
            }
        }
        dp[i] = minsteps;
    }

    //p(i,dp.size(), dp);

    return dp[N - 1];
    // TC : O(N) -> visiting all the index
    // SC : O(N) -> Additional vector
}

void solve()
{
    int K;
    cin>>N>>K;
    vector<int>arr(N);
    for (int i = 0; i < (int)N; i++)
    {
        cin >> arr[i];
    }    
    vector<int>dp(N,-1);
    cout<<memo(N-1,dp,arr,K)<<endl;
    cout<<tabu(N,dp,arr,K)<<endl;
    // cout<<space_opti(N,dp,arr)<<endl;
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