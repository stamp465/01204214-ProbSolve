#include<bits/stdc++.h>
using namespace std;

int N,M,status=1;
string s[100500];
int arr[50][50];

int dfs(int x,int y){		//1 = forest    2 = wow  3 = all
	arr[x][y] = 1;
	if( x == N-2 ) status = 0;
	if(x+1 >= 0 && x+1 < N && arr[x+1][y] == 0 )	dfs(x+1,y);
	if(x-1 >= 0 && x-1 < N && arr[x-1][y] == 0 )	dfs(x-1,y);
	if(y+1 >= 0 && y+1 < M && arr[x][y+1] == 0 )	dfs(x,y+1);
	if(y-1 >= 0 && y-1 < M && arr[x][y-1] == 0 )	dfs(x,y-1);

}

int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> s[i];
	}
	for(int i=0;i<N-1;i++){
		for(int j=0;j<M-1;j++){
			if( s[i][j] == '.' && s[i+1][j] == '.' && s[i][j+1] == '.' && s[i+1][j+1] == '.' ){
				arr[i][j] = 0;
			}
			else	arr[i][j] = 1;
			//cout << arr[i][j];
		}//cout<<endl;
	}
	for(int j=0;j<M-1;j++){
		if(arr[0][j]==0) dfs(0,j);
	}
	printf("%s\n", status==1? "no": "yes");
}

/*
7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
..........###.
####...######.
...#..##..###.

7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
........#####.
####...######.
...#..##..###.


*/
