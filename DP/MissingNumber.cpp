#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;  cin >> n;
    vector<long long> v(n-1);
    long long sum = 0;
    for(long long &x: v){
        cin >> x;
        sum+=x;
    }
    long long total = (n * (n+1))/2;
    cout<< total - sum;
    return 0;
}