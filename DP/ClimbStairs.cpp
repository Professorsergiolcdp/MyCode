#include<bits/stdc++.h>
using namespace std;
int dp[10000];
int helper(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = helper(n-1) + helper(n-2);

}
int main(){
    int n;  cin >> n;
    memset(dp,-1,sizeof(dp));
    cout<<helper(n);
}