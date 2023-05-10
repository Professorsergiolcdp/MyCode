#include<bits/stdc++.h>
#define ll long long 
#define forn(i,e) for(ll i = 0; i < e; i++)
using namespace std;

  int coinChange(vector<int>& coins, int amount) {
        int dp[coins.size() + 1][amount + 1];
        for(int i = 0; i <= amount; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= coins.size(); i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= coins.size(); i++){
            for(int j = 1; j <= amount; j++){
                // including the coin
                int x = coins[i -1] > j ? 0 : dp[i][j - coins[i - 1]];
                // excluding the coin
                int y = dp[i - 1][j];
                dp[i][j] = x + y;
            }
        }
        forn(i,coins.size()+1){
            forn(j,amount+1){
              cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[coins.size()][amount];
    }
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   vector<int> v = {1,2,5};
    int n = 11;
    cout<<coinChange(v,n);
}