/*
Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

void stockBuy(int *arr, int n)
{
    int minPrice = INT_MAX; 
    int maxProfit = 0;
    for(int i = 0; i < n; ++i)
    {
        minPrice = min(minPrice,arr[i]);
        maxProfit =  max(maxProfit,arr[i]-minPrice);
    }
    cout<<maxProfit<<"\n";
}
void solve()
{
    cin>>N;
    int *arr=new int[N];
    for (int i = 0; i <(int) N; i++)
    {
        cin>>arr[i];
    }
    stockBuy(arr,N);
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