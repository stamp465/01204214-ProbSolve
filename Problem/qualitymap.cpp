#include<bits/stdc++.h>
using namespace std;
int N,M;
int ans[5];
int visit[50][50];
int arr[50][50];
string s[50];
int status;

int dfs(int x,int y,int count){		//1 = forest    2 = wow  3 = all
	int c1=0,c2=0,c3=0,c4=0;
	visit[x][y] = 1;
	
	if(s[x][y]=='*' && status == 0) status = 1;
	else if(s[x][y]=='$' && status == 0) status = 2;
	else if(s[x][y]=='$' && status == 1) status = 3;
	else if(s[x][y]=='*' && status == 2) status = 3;
	//printf("%d %d %d\n",x,y,status);
	if(x+1 >= 0 && x+1 < N && visit[x+1][y] == 0 && s[x+1][y] != '#')	c1 = dfs(x+1,y,count);
	if(x-1 >= 0 && x-1 < N && visit[x-1][y] == 0 && s[x-1][y] != '#')	c2 = dfs(x-1,y,count);
	if(y+1 >= 0 && y+1 < M && visit[x][y+1] == 0 && s[x][y+1] != '#')	c3 = dfs(x,y+1,count);
	if(y-1 >= 0 && y-1 < M && visit[x][y-1] == 0 && s[x][y-1] != '#')	c4 = dfs(x,y-1,count);
	count = c1 + c2 + c3 + c4;
	return count+1;
}
int main(){

	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> s[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visit[i][j]==0 && s[i][j] != '#')	{
				status = 0;
				//printf("%d %d %d\n",i,j,status);
				int c = dfs(i,j,0);
				ans[status] += c;
				
				
				/*for(int xx=0;xx<N;xx++){
					for(int yy=0;yy<M;yy++){
						cout << visit[xx][yy];
					}cout << "\n";
				}*/
				//printf("%d %d %d %d %d\n",status,ans[0],ans[1],ans[2],ans[3]);
				
			}
		}
	}
	cout << ans[3] << " " << ans[1]+ans[2] ;
}

/*
7 8
.*..#...
....#...
.$.#..*#
..#..##.
.#.##...
#....###
..$.....
*/
