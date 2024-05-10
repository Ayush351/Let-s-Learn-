/*
roblem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

void nextpermutation(vector<int>&arr)
{
    int ind =-1;
    for(int i=(int)arr.size()-2;i>=0;i--) {
        if(arr[i]<arr[i+1])
        {
            ind = i;
            break;
        }
    }
    if(ind!=-1)
    {
        for(int i=(int)arr.size()-1;i>=0;i--)
        {
            if(arr[ind]>arr[i])
            continue;
            else
            {
                swap(arr[ind],arr[i]);
                reverse(arr.begin()+ind+1,arr.end());
                break;
            }
        }
    }
    for (int i = 0; i < (int)N; i++)
    {
        cout << arr[i] << " ";
    }    
}
void solve()
{
    cin>>N;
    vector<int> arr(N);
    for (int i = 0; i < (int)N; i++)
    {
       cin>>arr[i];
    }    
    nextpermutation(arr);
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