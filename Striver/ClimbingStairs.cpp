//https://leetcode.com/problems/climbing-stairs/description/
#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
        int previous=0,next=1;
        int ans = 0;
        for(int i =1;i<=n;i++)
        {
            ans = previous + next;
            previous = next;
            next  =  ans;
        }
        return ans;
    }
int main(){
    int N;
    cin >> N;
    cout << climbStairs(N) << endl;
}