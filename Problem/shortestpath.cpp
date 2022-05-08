#include<bits/stdc++.h>         ///https://www.proprog.tk/tasks/sssp/descs/7706
using namespace std;            /// distar algor
#define pii pair<int,int>
#define x first
#define y second

int n,m,s,t;
int dis[1000000];
char outp[1000000];
vector<pii> g[1000000];

int main() {
	scanf("%d %d",&n,&m);
	s = 1;
	t = n;
	for(int i=0; i<n+1; i++) dis[i] = 1e9;
	for(int i=0,u,v,weight; i<m; i++) {
		scanf("%d %d %d",&u,&v,&weight);
		g[u].emplace_back(v,weight);
		g[v].emplace_back(u,weight);
	}
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.emplace(dis[s] = 0, s);
	while(!Q.empty()) {
		auto u = Q.top();
		Q.pop();
		for(auto v : g[u.second]) {
			if(dis[v.first] > u.first + v.second) {
				Q.emplace(dis[v.first] = u.first + v.second , v.first);
			}
		}
		
	}
	printf("%d", dis[t]);
}



