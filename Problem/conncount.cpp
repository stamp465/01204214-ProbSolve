#include<bits/stdc++.h>
using namespace std;

int visit[100050];
vector<int> vec[100050];

int dfs(int node){
	visit[node] = 1;
	for(int i=0;i<vec[node].size();i++){
		if(visit[ vec[node][i] ]==0){
			dfs(vec[node][i]);
		}
	}
}

int main(){
	int N,M,c=0;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		vec[x].emplace_back(y);
		vec[y].emplace_back(x);
	}
	for(int i=1;i<=N;i++){
		if(visit[i]==0){
			dfs(i);
			c++;
		}
	}
	cout << c;
}
