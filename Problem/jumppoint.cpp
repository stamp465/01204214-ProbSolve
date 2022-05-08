#include<bits/stdc++.h>
using namespace std;

int N,R,minn[15000];
pair<int,int> q[15000];
vector<int> vec[15000];

int bfs(int start){
	
	queue<pair<int,int>> qq;
	qq.push({start,0});
	
	while(!qq.empty()){
		pair<int,int> now = qq.front();
		qq.pop();
		//visit[now.first] = 1;
		//cout << now.first << " " << now.second << "\n";
		for(int i=1;i<=N+1;i++){
		//	if(visit[i]==0){
				//printf("...%d %d %d %d\n",q[now.first].first,q[now.first].second,q[i].first,q[i].second);
				int x = abs(q[now.first].first - q[i].first);
				int y = abs(q[now.first].second - q[i].second);
				//cout << x << "---" << y << "\n";
				if(x*x+y*y <= R*R){
					if( now.second+1 < minn[i] ){
						minn[i] = now.second+1;
						qq.push({i,now.second+1});
					}
					/*else{
						qq.push({i,now.second+1});
					}*/
				}
		//	}
		}
	}
}

int main(){
	cin >> N >> R;
	q[0] = {0,0};
	minn[0] = 1e9;
	for(int i=1;i<=N;i++){
		cin >> q[i].first >> q[i].second;
		minn[i] = 1e9;
	}
	q[N+1] = {100,100};
	minn[N+1] = 1e9;
	bfs(0);
	if(minn[N+1]!=1e9)	cout << minn[N+1];
	else				cout << "-1";
}

/*
5 60
50 0
100 0
100 50
50 30
70 50

5 50
50 0
100 0
100 50
50 30
70 50

*/
