// kth largest element in a 2d array sorted row-wise and
// column-wise
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int mat[4][4], int n, int k)
{
	// USING LAMBDA FUNCTION
	// [=] IN LAMBDA FUNCTION IS FOR CAPTURING VARIABLES WHICH
	// ARE OUT OF SCOPE i.e. mat[r]
	// NOW, IT'LL COMPARE ELEMENTS OF HEAP BY ELEMENTS AT mat[first][second]
	// Capturing the value of mat by reference to prevent copying
	auto cmp = [&](pair<int,int> a,pair<int,int> b){
		return mat[a.first][a.second] > mat[b.first][b.second];
	};
	
	//DECLARING priority_queue AND PUSHING FIRST ROW IN IT
	priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
	for(int i=0; i<n; i++){
		pq.push({i,0});
	}
	
	//RUNNING LOOP FOR (k-1) TIMES
	for(int i=1; i<k; i++){
		auto p = pq.top();
		pq.pop();
		
		//AFTER POPPING, WE'LL PUSH NEXT ELEMENT OF THE ROW IN THE HEAP
		if(p.second+1 < n) pq.push({p.first,p.second + 1});
	}
	// ON THE k'th ITERATION, pq.top() will be our answer.
	return mat[pq.top().first][pq.top().second];
}

// driver program to test above function
int main()
{
	int mat[4][4] = {
		{ 10, 20, 30, 40 },
		{ 15, 25, 35, 45 },
		{ 25, 29, 37, 48 },
		{ 32, 33, 39, 50 },
	};
	cout << "7th smallest element is "
		<< kthSmallest(mat, 4, 7);
	return 0;
}
