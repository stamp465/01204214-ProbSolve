#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;


int main(){
	int N;
	cin >> N;
	for(int k=1;k<=N;k++){
		int dis[30000];
		vector<pair<int,int> > vec[30000];
		
		int n,m,st,en;
		cin >> n >> m >> st >> en;
		for(int i=0;i<=n;i++){
			dis[i] = 1e9;
			//vec[i].clear();
		}	
		dis[st] = 0;
		for(int x,y,z,i=0;i<m;i++){
			cin >> x >> y >> z;
			vec[x].emplace_back(make_pair(y,z));
			vec[y].emplace_back(make_pair(x,z));
		}
		
		priority_queue<pi, vector<pi>, greater<pi> > q;
		q.push(make_pair(0,st));
		int ch=0;
		while(!q.empty()){
			auto x = q.top();
			q.pop();
			int nowdis = x.first;
			int now = x.second;
			//printf("%d %d\n",now,nowdis);
			for(int i=0;i<vec[now].size();i++){
				int go = vec[now][i].first;
				//printf("%d\n",go);
				if( dis[go] > nowdis + vec[now][i].second ){
					dis[go] = nowdis + vec[now][i].second;
					q.push(make_pair(dis[go],go));
				}
			}
			//if(ch==1)	break;
			
		}
		if( dis[en] == 1e9)	printf("Case #%d: unreachable\n",k);
		else				printf("Case #%d: %d\n",k,dis[en]);
		
	}
}

/*
3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1
*/
