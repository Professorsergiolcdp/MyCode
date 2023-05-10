#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
	
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	int x;	cin >> x;
	int n,m;	cin >> n >> m;
	vector<int> flightF(n),flightT(n);
	vector<int> adj[x];
	for(int i = 0; i < n; i++)
	{
		cin >> flightF[i];
	}

	for(int i = 0; i < n; i++)
	{
		cin >> flightT[i];
	}
	for(int i = 0; i < n; i++)
	{
		adj[flightT[i]].push_back(flightF[i]);
	}

	vector<int> delay(m);
	queue<int> q;
	vector<int> ans;
	for(int i = 0; i < m; i++)
	{
		cin >> delay[i];
		q.push(delay[i]);

	}
	while(!q.empty())
	{
		int flightDelay = q.front();
		q.pop();
		ans.push_back(flightDelay);
		for(auto child: adj[flightDelay])
		{
			q.push(child);
		}	
		// cout<<flightDelay<<" ";
	}
	
	sort(ans.begin(),ans.end());
	for(auto x: ans)	cout<<x<<" ";

	return 0;
}
