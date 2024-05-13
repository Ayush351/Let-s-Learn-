/*
Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
*/


#include<bits/stdc++.h>
using namespace std;
//#define int long long

#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
            for(auto &v : nums1)
            {
                cout<<v<<" ";
            }
            cout<<"\n";
        }
    }
void solve()
{
    int N,M;
    cin>>N>>M;
    vector<int> nums1(N),nums2(M);
    for(int  i= 0;i<N;i++)
    {
        cin >>nums1[i];
    }
    for(int i=0;i<M;i++){
        cin >>nums2[i];
    }
    merge(nums1,N-M,nums2,M);
    // for(auto it : nums1){
    //     cout<<it<<" ";
    // }
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