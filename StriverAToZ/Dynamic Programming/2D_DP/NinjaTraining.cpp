/*
Problem Statement: A Ninja has an ‘N’ Day training schedule. He has to perform one
of these three activities (Running, Fighting Practice, or Learning New Moves) 
each day. There are merit points associated with performing an activity each day. 
The same activity can’t be performed on two consecutive days. We need to find the 
maximum merit points the ninja can attain in N Days.
*/

#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, N;
#define p(i,n,vect) for(int i=0;i<(int)n;++i) {cout<<vect[i]<<" ";} cout<<"\n";


/*

0 - points[i][1] && points[i][2];
1 - points[i][0] && points[i][2];
2 - points[i][0] && points[i][1];
3 - points[i][0] && points[i][1] && points[0][2]

*/

int tabu(int N,vector<vector<int>>&points)
{
    // Initialize the DP table for the first day (day 0)
    vector<vector<int>> dp(N, vector<int>(4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < N; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {    
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }
  }
  return dp[N - 1][3];
}

int space_opti(int N,vector<vector<int>>&points)
{
    vector<int>prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][1],points[0][0]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1;day< N;day++)
    {
        vector<int> temp(4, 0);
        for(int last = 0;last < 4;last++)
        {
            temp[last] = 0;
            for(int task = 0;task <3;task++)
            {
                if(task!= last)
                {
                    temp[last] = max(temp[last],points[day][task]+prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

void solve()
{
    
    vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};
    int N = points.size();
    //cout<<tabu(N,points)<<endl;
    cout<<space_opti(N,points)<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
   
        solve();
}