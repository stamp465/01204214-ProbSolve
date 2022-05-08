#include<bits/stdc++.h>
using namespace std;

int stx,sty,enx,eny;
int N,M,minn=1e9;
string s[10000];
int dis[1000][1000];

int xx[4] = {0,1,0,-1};
int yy[4] = {1,0,-1,0};


int dfs(int x,int y,int status,int disnow){
	//cout << x << " " << y << "\n";
	dis[x][y] = min(dis[x][y],disnow);
	if( dis[x][y] < disnow )	return 0;
	if( s[x+1][y] != '#' && dis[x+1][y] > disnow+1 ){
		if( s[x+1][y] == '.' ){
			dfs(x+1,y,status,disnow+1);
		}
		if( s[x+1][y] == '|' && s[x+2][y] == '.' ){
			dfs(x+2,y,status,disnow+2);
		}
	}
	if( s[x-1][y] != '#' && dis[x-1][y] > disnow+1 ){
		if( s[x-1][y] == '.' ){
			dfs(x-1,y,status,disnow+1);
		}
		if( s[x-1][y] == '|' && s[x-2][y] == '.' ){
			dfs(x-2,y,status,disnow+2);
		}
	}
	if( s[x][y+1] != '#' && dis[x][y+1] > disnow+1 ){
		if( s[x][y+1] == '.' ){
			dfs(x,y+1,status,disnow+1);
		}
		if( s[x][y+1] == '-' && s[x][y+2] == '.' ){
			dfs(x,y+2,status,disnow+2);
		}
	}
	if( s[x][y-1] != '#' && dis[x][y-1] > disnow+1 ){
		if( s[x][y-1] == '.' ){
			dfs(x,y-1,status,disnow+1);
		}
		if( s[x][y-1] == '-' && s[x][y-2] == '.' ){
			dfs(x,y-2,status,disnow+2);
		}
	}
}

int main(){
	
	cin >> N >> M;

	cin >> stx >> sty >> enx >> eny;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			s[i].push_back('#');
			dis[i][j] = 1e9;
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> s[i][j];
		}
	}
	
	/*for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout << s[i][j];
		}cout << "\n";
	}*/
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(s[i][j]=='*'){
				
				s[i][j] = '|';
				for(int i1=1;i1<=N;i1++){
					for(int j1=1;j1<=M;j1++){
						dis[i1][j1] = 1e9;
					}
				}
				dfs(stx,sty,0,0);
				minn = min(minn,dis[enx][eny]);
				
				s[i][j] = '-';
				for(int i1=1;i1<=N;i1++){
					for(int j1=1;j1<=M;j1++){
						dis[i1][j1] = 1e9;
					}
				}
				dfs(stx,sty,0,0);
				minn = min(minn,dis[enx][eny]);
				
				s[i][j] = '*';
			}
		}
	}
	
	
	if( minn == 1e9 ) cout << "-1";
	else	cout << minn;
	
	
	
}
/*
5 5
2 3 4 4
#####
#..##
#.*.#
#.#.#
#####
*/

