/*
Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long

#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";
void transpose(vector<vector<int>>&vect)
{
    for(int i=0;i<vect.size();++i)
    {
        for(int j=i+1;j<vect.size();++j)
        {
            swap(vect[i][j],vect[j][i]);
        }
    }

}
void rotateclockwise(vector<vector<int>>&vect){
    for(int i=0;i<vect.size();++i)
    {
        reverse(vect[i].begin(),vect[i].end());
    }
}
void rotateanticlockwise(vector<vector<int>>&vect){
    transpose(vect);
    int N = vect.size();
    for(int i=0;i<N;++i)
    {
        for(int j = 0;j<N/2;j++)
        {
            swap(vect[j][i],vect[N-j-1][i]);
        }
    }
}


void solve()
{
    int  N,M;
    cin>>N>>M;
    vector<vector<int>> vect(N, vector<int>(M));
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j)
        {
            cin >>vect[i][j];
        }
    }
    transpose(vect);
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j)
        {
            cout <<vect[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    
    rotateclockwise(vect);
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j)
        {
            cout <<vect[i][j]<<" ";
        }
        cout<<"\n";
    }
     cout<<"\n";
    rotateanticlockwise(vect);
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j)
        {
            cout <<vect[i][j]<<" ";
        }
        cout<<"\n";
    }
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