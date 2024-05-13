/*
Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.
*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";
 void  findRepeatingAndMissingNumbers(int *arr,int N)
 {
    // S - sum of numbers
    // Sn - sum of first N natural numbers

    // s2 - sum square of numbers
    // sn2 -  sum of square of first N natural numbers
    long long S = 0,Sn = 0,S2 = 0,Sn2 = 0;

    Sn = ( N * (N+1))/2;
    Sn2 = (N  * (N+1) * (2*N +1))/6;

    for(int i = 0;i< N;i++)
    {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    int val1  =  Sn - S;   // x - y
    int val2  =  (Sn2 - S2); // x^2 - y^2

    // cout<<val1<<" "<<val2<<"\n";

    val2  =  val2/val1;  // x+y

    int x = (val1 + val2) /2;
    int y = x - val1;

    cout << x <<" "<<y;

 }
void solve()
{
    cin>>N;
    int *arr=new int[N];
    for (int i = 0; i <(int) N; i++)
    {
        cin>>arr[i];
    }
    findRepeatingAndMissingNumbers(arr,N);   
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