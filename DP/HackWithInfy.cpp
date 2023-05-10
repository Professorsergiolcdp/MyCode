#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> candies,int x,long long k){
        long long child = 0;
        for(int i = 0;i < candies.size() ;i++){
            child += candies[i] / x;
        }
        if(child >= k){
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int i = 0;i < candies.size() ; i++){
            sum += candies[i];
        }
        if(k > sum){
            return 0;
        }
        int s = 1,e = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(s <= e){
            int mid = (s+e) / 2;
    
            if(isValid(candies,mid,k)){
                // cout<<mid<<endl;   
                ans = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
                // cout<<mid<<endl;
            }
        }
        return ans;
        
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  vector<int> candies = {5,8,6};
  long long k = 3;
  cout<<maximumCandies(candies,k)<<endl;

}