/*
Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.
*/


#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";
void maxSumArray(int arr[],int N)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i=0;i<N;i++)
    {
        if(sum == 0)
        start = i;

        sum += arr[i];

        if(sum > maxSum) {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum<0)
        {
            sum =0;
        }
    }
    cout<<"Subarray : ";
    for (int i = ansStart; i <= (int)ansEnd; i++)
    {
        cout<<arr[i]<<" ";
    }    
}
void maxSum(int *arr,int N)
{
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<N;i++){
        sum+=arr[i];
        if(sum>maxSum){maxSum=sum;}
        if(sum<0)sum = 0;
    }
    cout<<maxSum<<"\n";
}
void solve()
{
    cin>>N;
    int *arr=new int[N];
    for (int i = 0; i <(int) N; i++)
    {
        cin>>arr[i];
    }
    maxSum(arr,N);
    maxSumArray(arr,N);
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