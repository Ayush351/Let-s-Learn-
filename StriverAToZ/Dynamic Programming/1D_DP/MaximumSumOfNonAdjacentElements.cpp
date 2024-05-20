/*
Given an array of ‘N’  positive integers, we need to return the maximum sum
 of the subsequence such that no two elements of the subsequence are adjacent elements in the array.
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

int memo(int ind,vector<int>&dp,vector<int>&arr)
{
    //base case
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + memo(ind -2,dp,arr);
    int not_picked = 0 + memo(ind - 1,dp,arr);

    return dp[ind] = max(pick,not_picked);
     // TC : O(N) -> visiting all the index
    // SC : O(N) -> Additional vector + recursion stack
}

int tabu(int N,vector<int>&dp,vector<int>&arr)
{
    dp[0]=arr[0];

    for(int i =1;i<N;i++)
    {
        int picked = arr[i];
        if(i > 1) 
        picked+= dp[i-2];
        int not_picked = dp[i-1];
        dp[i] =  max(picked,not_picked);
    }
    
    return dp[N-1];
    // TC : O(N) -> visiting all the index
    // SC : O(N) -> Additional vector
}
int space_opti(int N,vector<int>arr)
{
    int prev1 = arr[0];
    int prev2 = -1;

    for(int i = 1;i<N;i++)
    {
        int picked = arr[i];
        if(i >1)
        picked += prev2;
        int not_picked = prev1;
        
        int curr = max(picked,not_picked);
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
    vector<int>arr(N);
    for (int i = 0; i < (int)N; i++)
    {
        cin >> arr[i];
    }    
    vector<int>dp(N,-1);
    cout << memo(N-1, dp , arr)<<endl;
    cout << tabu(N, dp , arr)<<endl;
    cout << space_opti(N,arr)<<endl;
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