/*
Problem Statement: This problem has 3 variations. They are stated below:

Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long

#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";


void var1(int N, int R)
{
    N -=1;
    R -=1;
    int ans = 1;
    for(int i=0;i<R;++i){
        ans = ans * (N- i);
        ans = ans / (i+1);
    }
    cout<<ans<<endl;
}
void var2(int N)
{
    int ans = 1;
    cout<<ans<<" ";
    for(int i =1;i<N;i++)
    {
        ans = ans * (N-i);
        ans = ans / (i);
        cout<<ans<<" ";
    }

}
void var3(int N){
     cout<<endl;
    for(int i = 1;i<=N;i++)
    {
        var2(i);
        cout<<endl;
    }
    
}
void solve()
{
   
    int N=5,R=3,M=5;
    var1(N,R);
    var2(N);
    var3(M);
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