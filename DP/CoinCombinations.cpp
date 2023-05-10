#include<iostream>
#include<vector>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;   cin >>  n >> k;
    vector<int> coin(n);
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }
    int MOD = 1e9+7;
    vector<vector<int> > dp(n+1,vector<int>(k+1));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j == 0){
                dp[i][j] = 1;
            }else{
                int x = (coin[i - 1] > j) ? 0 : dp[i][j - coin[i - 1]];
                int y = (i == 1) ? 0 : dp[i - 1][j];
                dp[i][j] = (x + y) % MOD;
            }
        }
    }
    cout<<dp[n][k]<<endl;
}