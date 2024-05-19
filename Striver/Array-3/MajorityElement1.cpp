/*
Find the Majority Element that occurs more than N/2 times
Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";
void solve()
{
    cin>>N;
    int *arr=new int[N];
    for (int i = 0; i <(int) N; i++)
    {
        cin>>arr[i];
    }
    int cnt = 0;
    int ele;

    for(int i= 0;i<N;i++)
    {
        if(cnt == 0)
        {
            ele=arr[i];
            cnt++;
        }
        else if(ele == arr[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int cnt_maj = 0;
    for(int i =0;i<N;i++)
    {
        if(arr[i] == ele)
        cnt_maj++;
    }
    if(cnt_maj > N/2)
    cout<<ele<<"\n";
    else
    cout <<-1<<"\n";
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