// find maximum sum of elements of array after applying the operation - replacing a subarray with 0

#include<bits/stdc++.h>
using namespace std;

int findMaxSubarraySum(vector<int> arr,int start,int end){
    int mid = (start + end) >> 1;
    int leftSum = 0;
    for(int i = mid - 1; i > 0 ; i--){
            
    }
}
int main(){
    int n; cin >> n;
    vector<int> arr(n);
    int neg = 0;
    for(int &x: arr) {
        cin >> x;
        if(x < 0)   neg++;
    }
    if(neg > 0){

    } 
    else{
        findMaxSubarraySum(arr,0,n);
    }
}