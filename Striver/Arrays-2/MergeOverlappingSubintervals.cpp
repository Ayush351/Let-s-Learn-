/*
Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
*/


#include<bits/stdc++.h>
using namespace std;
//#define int long long

#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

void mergeOverlapping(vector<vector<int> >&arr)
{
    vector<vector<int> >ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < (int)arr.size(); i++)
    { 
        if(ans.empty() ||  arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }
    for(auto& it : ans)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
}
void solve()
{
    int N,M;
    cin>>N>>M;
    vector<vector<int> >arr(N,vector<int>(M));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>arr[i][j];
        }
    }
    mergeOverlapping(arr);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
        solve();
}