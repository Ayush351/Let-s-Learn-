/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";

string prefix(vector<string>s)
{
    int flag = 0;string ans="";
    for(int j = 0;j<s[0].size();j++)
    {
        for(int i  =0 ;i<s.size();i++)
        {
            flag  = 0;
            if( s[i][j] == s[0][j])
            {
                flag = 1;
            }
            else
            {
                break;
            }
        }
        if(flag)
        ans += s[0][j];
       
    }
    return ans;
}
void solve()
{
    vector<string>s;
    s={"Flower","Flow","Flight"};

    cout<<prefix(s);
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