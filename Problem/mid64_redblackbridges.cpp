#include<bits/stdc++.h>
using namespace std;

int visit[200005][5];
int dis[200005];

vector< pair<int,int> > vec[200005];


void bfs(int start,int endd){
	dis[start] = 0;
	tuple<int,int,int> p;
	p = make_tuple(start,0,0);
	queue< tuple<int,int,int> > q;
	q.push(p);
	
	while(!q.empty()){
		int node,status,nowdis;
		tuple<int,int,int> f = q.front();
		node = get<0>(f);
		status = get<1>(f);
		nowdis = get<2>(f);
		q.pop();
		
		if( visit[node][status] == 1) continue;
		visit[node][status] = 1;
		//cout << node << "---" << status << "dis " << nowdis << "\n";
		for(int i=0;i<vec[node].size();i++){
			
			//if( visit[ vec[node][i].first ][ vec[node][i].second ] == 0){
				if( status==0 ){
					//cout << "cango1 " << vec[node][i].first << " " << vec[node][i].second << "\n";
					dis[ vec[node][i].first ] = min(dis[ vec[node][i].first ],nowdis+1);
					tuple<int,int,int> go = make_tuple(vec[node][i].first,vec[node][i].second,nowdis+1);
					
					if(vec[node][i].first!=endd) 
					q.push(go);
				}
				else if( status==vec[node][i].second ){
					//cout << "cango2 " << vec[node][i].first << " " << vec[node][i].second << "\n";
					dis[ vec[node][i].first ] = min(dis[ vec[node][i].first ],nowdis+1);
					tuple<int,int,int> go = make_tuple(vec[node][i].first,vec[node][i].second,nowdis+1);
					
					if(vec[node][i].first!=endd) 
					q.push(go);
				}
				else if( vec[node][i].second==0 ){
					//cout << "cango1 " << vec[node][i].first << " " << vec[node][i].second << "\n";
					dis[ vec[node][i].first ] = min(dis[ vec[node][i].first ],nowdis+1);
					tuple<int,int,int> go = make_tuple(vec[node][i].first,status,nowdis+1);
					
					if(vec[node][i].first!=endd) 
					q.push(go);
				}
			//}
			
		}
		
	}
	
	
}

int main(){
	int N,M,S,T;
	cin >> N >> M >> S >> T;
	for(int i=0;i<=N;i++)	dis[i] = 1e9;
	for(int i=0;i<M;i++){
		int a,b,c;
		pair<int,int> p1,p2;
		cin >> a >> b >> c;
		p1 = { b,c };
		p2 = { a,c };
		vec[a].emplace_back(p1);
		vec[b].emplace_back(p2);
	}
	bfs(S,T);
	/*for(int i=0;i<=N;i++){
		cout << i << " " << dis[i] << "\n";
	}*/
	if(dis[T]==1e9){
		cout << "-1";
		return 0;
	}
	cout << dis[T];
}
