#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;   cin >> s;
    cout<<s<<endl;
    int n = s.size();   
    int dp[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }
   for(int l = 2; l <= n; l++){
       for(int i = 0; i < n - l + 1; i++){
           
          int j = i + l - 1;
          if(s[i] == s[j] && l == 2){
              dp[i][j] = 2;
          }else if(s[i] == s[j]){
              dp[i][j] = dp[i+1][j-1] + 2;
          }else{
              dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
          }
       }
       for(int i = 0;i < n; i++){
           for(int j = 0;j < n; j++){
               cout<<dp[i][j]<<" ";
           }
           cout<<endl;
       }
   }
    return 0;
}

// dp[1][2]    dp[2][3]    dp[3][4]    dp[4][5]
