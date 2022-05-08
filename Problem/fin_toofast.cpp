#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define tup tuple<int, int, int>
#define x first
#define y second

int visit[100000][2];
int dis[100000][2];
vector< tup > vec[100000];
int n,m;
int main(){
	cin >> n >> m;
	for(int i=0,u,v,w,s;i<m;i++){
		cin >> u >> v >> w >> s;
		vec[u].push_back( make_tuple(v,w,s) );
		vec[v].push_back( make_tuple(u,w,s) );
	}
	for(int i=0;i<n+2;i++){
		dis[i][0] = 1e9;
		dis[i][1] = 1e9;
	}
	priority_queue<tup, vector<tup>, greater<tup> > Q;
	Q.emplace(make_tuple(dis[1][0]=0,1,0));		//disnow now useS
	//cout << "start\n";
	while(!Q.empty()) {
		auto u = Q.top();
		int disnow, now, useS;
		tie(disnow, now, useS) = Q.top();
		//cout << "NOW = " << disnow << " " << now << " " << useS << "\n";
		
		Q.pop();
		for(auto v : vec[now]) {
			int go, disgo, S;
			tie(go, disgo, S) = v;
			if( S==1 && useS == 1)	continue;
			
			int wills = useS;
			if( S==1 )	wills = S;
			
			if(dis[go][wills] > disnow + disgo) {
				//cout << "go = " << go << " " << disgo << " " << S << "\n";
				dis[go][wills] = disnow + disgo;
				Q.emplace( make_tuple( dis[go][wills], go, wills ) );
			}
		}
	}
	int ans = min(dis[n][0],dis[n][1]);
	if(ans==1e9)	ans = -1;
	printf("%d", ans);
}
