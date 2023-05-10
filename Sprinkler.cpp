#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> &a,const pair<int,int> &b){
    return a.first > b.first;
}

int main(){
    int n,q;  cin >> n >> q;
    vector<int> v(n),r(n);
    for(int i =0 ; i< n; i++){
        cin >> v[i];
    }
    for(int i= 0 ;i < n;i++){
        cin >> r[i];
    }
    vector<pair<int,int> > vr;
    for(int i= 0;i < n; i++){
        vr.push_back({v[i],r[i]});
    }
    int k = 0;
    sort(vr.begin(),vr.end(),comp);
    for(auto x: vr){
        int a = x.first;
        int b = x.second;
        if(a < 0){
            if(a+b > 0){
                vr[k].second = 0;
            }else{
                vr[k].second = a + b;
            }
            vr[k].first = a - b;
            k++;
        } 
        else{
            if(a - b < 0){
                vr[k].first = 0;
            }else{
                vr[k].first = a - b;
            }  
            vr[k].second = a + b;
            k++;
        }
    }
    for(auto x : vr){
        cout<<" ("<<x.first<<" "<<x.second<<"), ";
    }
    cout<<endl;
    for(int i = 0;i < q; i++){
        int query;  cin >> query;
        int cnt = 0;
        for(auto x: vr){
            if(query >= x.first && query <= x.second){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    cout<<endl;
    return 0;
}