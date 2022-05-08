#include<bits/stdc++.h>
using namespace std;

vector<int> vec[250000];
queue< pair<int,int> > for_bfs;
int visit[250000];
int dis[250000];
int N,M,S,T;

int main(){
	cin >> N >> M >> S >> T;
	
	for(int i=0,x,y;i<M;i++){
		cin >> x >> y;
		vec[x].emplace_back(y);
		vec[y].emplace_back(x);
	}
	for(int i=0;i<S;i++){
		int aaa;
		cin >> aaa;
		for_bfs.push({aaa,0});
		visit[aaa] = 1;
	}
	
	while(!for_bfs.empty()){
		int now = for_bfs.front().first;
		int disnow = for_bfs.front().second;
		for_bfs.pop();
		for(int i=0;i<vec[now].size();i++){
			int willgo = vec[now][i];
			if(visit[willgo]==1)	continue;
			visit[willgo] = 1;
			dis[willgo] = disnow + 1;
			for_bfs.push({willgo,disnow+1});	
		}		
	}
	
	/*for(int i=1;i<=N;i++){
		cout << dis[i] << "...\n";
	}*/
	
	for(int i=0;i<T;i++){
		int aaa;
		cin >> aaa;
		cout << dis[aaa] << "\n";
	}
}
