#include<bits/stdc++.h>
using namespace std;

int arr[100][100];
int visit[100][100];

int main(){
	for(int i=0;i<100;i++)	{
		for(int j=0;j<100;j++){
			arr[i][j] = -1;
		}
	}
	
	int N,K;
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> arr[i][j];
		}
	}
	

	pair<int,int> p;
	p = make_pair(1,1);
	queue< pair<int,int> > q;
	q.push(p);
	
	while(!q.empty()){
		int x,y;
		pair<int,int> f = q.front();
		x = f.first;
		y = f.second;
		q.pop();
		
		if( visit[x][y] == 1) continue;
		visit[x][y] = 1;
		//cout << x << "---" << y << "\n";
		
		if( arr[x+1][y] != -1 && arr[x+1][y] - arr[x][y] <= K )	q.push( make_pair(x+1,y) );
		if( arr[x-1][y] != -1 && arr[x-1][y] - arr[x][y] <= K )	q.push( make_pair(x-1,y) );
		if( arr[x][y+1] != -1 && arr[x][y+1] - arr[x][y] <= K )	q.push( make_pair(x,y+1) );
		if( arr[x][y-1] != -1 && arr[x][y-1] - arr[x][y] <= K )	q.push( make_pair(x,y-1) );
		
	}
	
	if( visit[N][N]!=0 )	cout << "yes";
	else					cout << "no";
	
}
