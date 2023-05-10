#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n,0),rightMax(n,0);
    leftMax[0] = height[0];
    for(int i = 1; i < n; i++){
        leftMax[i] = max(height[i],leftMax[i-1]);
    }
    rightMax[n - 1] = height[n-1];
    for(int i = n - 2; i >=0 ; i--){
        rightMax[i] = max(height[i],rightMax[i+1]);
    }
    for(int i = 0;i < n; i++)
        cout<<leftMax[i]<<" ";
    cout<<endl;
    for(int i = 0;i < n; i++)
        cout<<rightMax[i]<<" ";
    cout<<endl;
    int i = 0, j = n - 1;
    int ans = 0;
    for(int i = 1;i < n - 1;i++){
        if(height[i] <= min(leftMax[i],rightMax[i])){
            ans += (min(leftMax[i],rightMax[i]) - height[i]);
        }
    }
    return ans;
};
int main(){
    vector<int> h = {4,2,0,3,2,5};
    cout<<trap(h);
    return 0;
}