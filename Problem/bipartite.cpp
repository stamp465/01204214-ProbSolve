#include<bits/stdc++.h>
using namespace std;

vector<int> vec[100500];
int status = 0;
int color[100500];
int bfs(int start){
	color[start] = 1;
	queue<int> q;
	q.push(start);
	
	while(!q.empty() && status==0){
		int now = q.front();
		q.pop();
		
		for(int i=0;i<vec[now].size();i++){
			if(color[vec[now][i]] == color[now]){
				status = 1;
				break;
			}
			if(color[vec[now][i]] == 0){
				if(color[now]==1)	color[vec[now][i]] = 2;
				if(color[now]==2)	color[vec[now][i]] = 1;
				q.push(vec[now][i]);	
			}
		}
	}
}

int main(){
	int N;
	cin >> N;
	while(N--){
		int n,m;
		cin >> n >> m;
		for(int i=0;i<m;i++){
			int x,y;
			cin >> x >> y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		status = 0;
		bfs(1);
		printf("%s\n", status==1? "no": "yes");
		for(int i=1;i<=n;i++){
			vec[i].clear();
			color[i] = 0;
		}
	}
}

/*
2
3 3
1 2
2 3
3 1
4 3
1 2
1 3
4 1

*/
