#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<int> q;
vector<int> vec[150000];
int in_degree[150000];


int main(){
	cin >> n >> m;

	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		vec[x].emplace_back(y);
		in_degree[y]++;
	}
	for(int i=1;i<=n;i++){
		if( in_degree[i]==0 ){
			q.push(i);
		}
	}
	if(q.empty())	cout<<"no";
	while(!q.empty()){
		int now = q.front();
		cout << now << "\n";
		q.pop();
		for(int i=0;i<vec[now].size();i++){
			in_degree[ vec[now][i] ]--;
			if( in_degree[ vec[now][i] ]==0 ){
				q.push( vec[now][i]  );
			}
		}
	}
	
}
