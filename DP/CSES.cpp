#include<bits/stdc++.h>
using namespace std;

// to store downpath
vector<int> tree[200001];

vector<int> depth(200001);
vector<int> ans(2000001);

void calc_depth(int src,int par){
	int depth_src = 0;
	for(auto child: tree[src]){
		if(child != par){
			calc_depth(child,src);
			depth_src = max(depth_src,1 + depth[child]);
		}
	}
	depth[src] = depth_src;
}
// par_ans = partial ans without considering the children subtree of a 
// particular child 
void solve(int src,int par,int par_ans){

	vector<int> prefix,suffix;
	for(auto child: tree[src]){
		if(child != par){
			prefix.push_back(depth[child]);
			suffix.push_back(depth[child]);
		}
	}

	for(int i = 1; i < prefix.size(); i++){
		prefix[i] = max(prefix[i-1],prefix[i]);
	}

	for(int i = suffix.size() - 2; i >= 0 ; i--){
		suffix[i] = max(suffix[i+1],suffix[i]);
	}

	int c_no = 0;
	for(auto child: tree[src]){
		if(child != par){
			
			int op1 = (c_no == 0) ? INT_MIN : prefix[c_no - 1];
			int op2 = (c_no == suffix.size() - 1) ? INT_MIN : suffix[c_no+1];
			int partial_ans = 1 + max(par_ans, max(op1,op2));
			solve(child,src,partial_ans);
			c_no++;	
		}
	}
	int d_oc = prefix.size() == 0 ?  0: prefix.back();
	ans[src] = 1 + max(par_ans,d_oc);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a,b; 	cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	calc_depth(1,0);
	solve(1,0,0);
	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<" ";
	}	
}