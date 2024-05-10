// Problem Statement: Given a matrix if an element in the matrix is 0 
// then you will have to set its entire column and row to 0 and then return the matrix.

#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

vector<vector<int>> ansVector(vector<vector<int>>answer,int n,int m){
    int col0 = 1;
    for(int i=0;i<(int)n;++i)
    {
        for(int j=0;j<m;j++)
        {
            if(answer[i][j]==0)
            {
                answer[i][0] = 0;

                if(j!=0)
                {
                    answer[0][j] = 0;
                }
                else
                {
                    col0 =0;
                }
            }
        }
    }
    for(int i=1;i<(int)n;i++)
    {
        for(int j=1;j<m;j++)
        {
            // All the elements of the matrix except the first row and first column are marked as zero
            if(answer[i][0]==0 || answer[0][j]==0){
                answer[i][j] = 0;
            }
        }
    }
    if(answer[0][0]==0)
    {
        for(int i=0;i<m;i++)
        answer[0][i] = 0;
    }
    if(col0)
    {
        for(int i=0;i<n;i++)
        answer[i][0] = 0;
    }
    return answer;
}

void solve()
{
    int N,M;
    cin>>N>>M;
    vector <vector <int> >arr(N, vector <int>(M));
    for (int i = 0; i <(int) N; i++)
    {
        for(int j = 0; j <M; j++){
            cin >> arr[i][j];
        }
    }
    vector <vector<int>>ans =  ansVector(arr,N,M);
     for (int i = 0; i <(int) N; i++)
    {
        for(int j = 0; j <M; j++){
           cout<<ans[i][j]<<" ";
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
    T = 1;
    while (T--)
        solve();
}