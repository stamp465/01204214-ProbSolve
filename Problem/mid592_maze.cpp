#include<bits/stdc++.h>
using namespace std;

int visit[25][25][2];
string s[25];
int stx,sty,enx,eny,can=0;

int maze(int x,int y,int usekey){
	visit[x][y][usekey] = 1;
	if(x==enx && y==eny){
		can = 1;
		return 1;
	}
	if(visit[x+1][y][usekey]==0 && s[x+1][y]!='#'){
		if(s[x+1][y]=='O' && usekey==0)		maze(x+1,y,1);
		if(s[x+1][y]!='O')					maze(x+1,y,usekey);
	}
	if(visit[x-1][y][usekey]==0 && s[x-1][y]!='#'){
		if(s[x-1][y]=='O' && usekey==0)		maze(x-1,y,1);
		if(s[x-1][y]!='O')					maze(x-1,y,usekey);
	}
	if(visit[x][y+1][usekey]==0 && s[x][y+1]!='#'){
		if(s[x][y+1]=='O' && usekey==0)		maze(x,y+1,1);
		if(s[x][y+1]!='O')					maze(x,y+1,usekey);
	}
	if(visit[x][y-1][usekey]==0 && s[x][y-1]!='#'){
		if(s[x][y-1]=='O' && usekey==0)		maze(x,y-1,1);
		if(s[x][y-1]!='O')					maze(x,y-1,usekey);
	}
	
	
}

int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0;i<=N+1;i++){
		for(int j=0;j<=N+1;j++){
			s[i].push_back('#');
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> s[i][j];
		}
	}
	
	for(int i=0;i<M;i++){
		cin >> stx >> sty >> enx >> eny;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				visit[i][j][0]=0;
				visit[i][j][1]=0;
			}
		}
		can = 0;
		maze(stx,sty,0);
		if(can)		cout << "yes\n";
		else		cout << "no\n";
	}
	
	/*for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << s[i][j];
		}cout << "\n";
	}*/
}

/*
8 1
.......#
.......#
#####O.#
.......#
........
........
.....#OO
.....#..
1 1 8 8
*/

