/*
Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.
*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";
void findDup(int *arr,int N)
{
    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    while(slow!=fast);

    fast =arr[0];
    while(slow!=fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    cout<<slow<<"\n";
    
}
void solve()
{
    cin>>N;
    int *arr=new int[N];
    for (int i = 0; i <(int) N; i++)
    {
        cin>>arr[i];
    }
    findDup(arr,N);
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