#include<bits/stdc++.h>
using namespace std;

int main(){
    int W;  cin >> W;
    vector<int> wt  = {10,20,30};
    vector<int> val = {60,100,120};
    int n = sizeof(wt)/sizeof(int);
    int dp[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if(w <= wt[i - 1]){
                dp[i][w] = dp[i-1][w]; 
            }
            else{
                dp[i][w] = max(dp[i-1][w],val[i-1] + dp[i-1][w-wt[i - 1]]);
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1;j <= W; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][W]<<endl;
    return 0;
}