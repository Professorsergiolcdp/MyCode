#include<bits/stdc++.h>
using namespace std;
int dp[10000];
int s[1000];
int helper(vector<int> price,int n){
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int q = INT_MIN;
    for(int i = 1; i <= n;i++){
        // cout<<i<<endl;
        q = max(q,price[i-1] + helper(price,n-i));
    }
    return dp[n] = q;
}
int findMaxProfit(vector<int> const &price, int n)
{
    
    // Write your code here...
    memset(dp,-1,sizeof(dp));
    return helper(price,n);
}
int main(){
    int n;  cin >> n;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<findMaxProfit(price,n);
    return 0;
}