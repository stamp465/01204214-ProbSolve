#include<bits/stdc++.h>
using namespace std;

int N,M;
string s[10000];
int arr[300][300][3][3];			// 0 not go			1 $ 	2 $wall		3 @&$    -1 cant go
int sss[300][300][3][3];
int visit[300][300][3];
int can111 = 0,can222=0;
vector< pair<int,int> > savetotest;
pair<int,int> pos[100000];
int ipos = 0;
int maxx = -1;
int xx[4] = {0,1,0,-1};
int yy[4] = {1,0,-1,0};
// left 0 right 1
// not 0 go 1

int dfs(int x,int y,int LR,int breakwall){
	//printf("%d %d %d %d\n",x,y,LR,breakwall);
	if( arr[x][y][LR][breakwall] != 0 ){
		if( arr[x][y][LR][breakwall] == -1 )	visit[x][y][LR]++;
		return arr[x][y][LR][breakwall];
	}
	
	if( s[x][y] == '$' && breakwall==1 ){
		arr[x][y][LR][breakwall] = 2;
		return arr[x][y][LR][breakwall];
	}
	/*else if( s[x][y] == '$' ){
		arr[x][y][LR][breakwall] = 1;
		return arr[x][y][LR][breakwall];
	}*/
	
	
	int a1=0,a2=0,b1=0,b2=0,b3=0,c1=0,c2=0,c3=0,ccc=0;
	
	if( x+1 < N && s[x+1][y] != '#' ){
		ccc=1;
		a1 = dfs(x+1,y,LR,breakwall);
	}
	
	/*if( x+1 < N && s[x+1][y] == '#' ){
		if(breakwall == 0){
			a2 = dfs(x+1,y,LR,1);
		}
	}*/
	if(ccc==0){
		if( LR == 0 ){
			
			if( y-1 >= 0 && s[x][y-1] == '.'){
				b1 = dfs(x,y-1,LR,breakwall);
			}
			/*if( y-1 >= 0 && s[x][y-1] == '#'){
				if(breakwall == 0){
					b2 = dfs(x,y-1,LR,1);
				}
			}*/
			if( y == 0 ){
				b3 = dfs(x,y,1,breakwall);
			}
			
		}
		
		if( LR == 1 ){
			
			if( y+1 < M && s[x][y+1] == '.'){
				c1 = dfs(x,y+1,LR,breakwall);
			}
			/*if( y+1 < M && s[x][y+1] == '#'){
				if(breakwall == 0){
					c2 = dfs(x,y+1,LR,1);
				}
			}*/
			if( y == M-1 ){
				c3 = dfs(x,y,0,breakwall);
			}
			
		}
	}
	
	int check1=0,check2=0,check3=0;
	if(a1==1 || a2==1 || b1==1 || b2==1 || b3==1 || c1==1 || c2==1 || c3==1){
		check1 = 1;
	}
	if(a1==2 || a2==2 || b1==2 || b2==2 || b3==2 || c1==2 || c2==2 || c3==2){
		check2 = 1;
	}
	/*if(a1==3 || a2==3 || b1==3 || b2==3 || b3==3 || c1==3 || c2==3 || c3==3){
		check3 = 1;
	}
	if(check3 || (check1&&check2) ){
		arr[x][y][LR][breakwall] = 3;
		return arr[x][y][LR][breakwall];
	}*/
	if(check1){
		arr[x][y][LR][breakwall] = 1;
		return arr[x][y][LR][breakwall];
	}
	if(check2){
		arr[x][y][LR][breakwall] = 2;
		return arr[x][y][LR][breakwall];
	}
	
	
	arr[x][y][LR][breakwall] = -1;
	//if( arr[x][y][LR][breakwall] == -1 ){
		//visit[x][y][LR]++;
	//}
	
	return arr[x][y][LR][breakwall];
	
}

int s_uping(int x,int y,int LR,int breakwall,int uping,int ssx,int ssy){
	//
	if( sss[x][y][LR][breakwall] != 0 ) {
		//printf("re\n");
		return sss[x][y][LR][breakwall];
	}
	
	if( x==0 && breakwall==0 ){
		sss[x][y][LR][breakwall] = -1;
		return sss[x][y][LR][breakwall];
	}
	if( x==0 && breakwall==1 ){
		printf("%d %d %d %d %d %d %d\n",x,y,LR,breakwall,uping,ssx,ssy);
		int savex = x;
		int savey = y;
		int count_s = 0;
		int s_swap = 0;
		if( LR==0 ){
			for(int ii=0;;ii--){
				y = savey+ii;
				if( y < 0 ){
					s_swap = 1;
					y++;
					break;
				}
				if( s[x+1][y] == '.' && y!=savey ){
					break;
				}
				if( arr[x][y][1][0] == -1 )	count_s ++;		
				//printf("LR = 0 /// %d %d %d\n",savey,ii,y);			
			}
			if(s_swap){
				for(int ii=0;;ii++){
					y = y+ii;
					if( y >= M ){
						s_swap = 1;
						break;
					}
					if( s[x+1][y] == '.' && y!=savey ){
						break;
					}
					if( arr[x][y][0][0] == -1 )	count_s ++;	
					//printf("LR = 0 S /// %d %d %d\n",savey,ii,y);				
				}
			}
		}
		else{
			for(int ii=0;;ii++){
					y = savey+ii;
					if( y >= M ){
						s_swap = 1;
						break;
					}
					if( s[x+1][y] == '.' && y!=savey ){
						break;
					}
					if( arr[x][y][0][0] == -1 )	count_s ++;	
					//printf("LR = 1 /// %d %d %d\n",savey,ii,y);			
			}
			
			if(s_swap){
				for(int ii=0;;ii--){
					y = y+ii;
					if( y < 0 ){
						s_swap = 1;
						y++;
						break;
					}
					if( s[x+1][y] == '.' && y!=savey ){
						break;
					}
					if( arr[x][y][1][0] == -1 )	count_s ++;		
					//printf("LR = 1 S /// %d %d %d\n",savey,ii,y);			
				}
			}
		}
		maxx = max(maxx,count_s);
		//printf("test1\n");
		//printf("count = %d\n",count_s);
		//if(count_s!=0){
			savetotest.push_back(make_pair(count_s,ipos));
			pos[ipos] = {ssx,ssy};
			ipos++;
		//}
		
		
		sss[x][y][LR][breakwall] = -1;
		return sss[x][y][LR][breakwall];
	}
	
	if( uping==0 && s[x+1][y] != '#'  ){
		//sss[x][y][LR][breakwall] = -1;
		
		return -1;//sss[x][y][LR][breakwall];
	}
	
	
	
	int a1=0,a2=0,b1=0,b2=0,b3=0,c1=0,c2=0,c3=0,ccc=0;
	
	if( x-1 >= 0 && s[x-1][y] != '#' ){
		//ccc=1;
		a1 = s_uping(x-1,y,LR,breakwall,1,ssx,ssy);
	}
	
	if( x-1 >= 0 && s[x-1][y] == '#' ){
		if(breakwall == 0){
			a2 = s_uping(x-1,y,LR,1,1,x-1,y);
		}
	}	//printf("eiei %d\n",sss[x][y][LR][breakwall]);
	if(ccc==0){
		if( LR == 0 ){
			//printf("\ntest2 ");
			if( y-1 >= 0 && s[x][y-1] == '.'){
				b1 = s_uping(x,y-1,LR,breakwall,0,ssx,ssy);
			}
			if( y-1 >= 0 && s[x][y-1] == '#'){
				if(breakwall == 0){
					b2 = s_uping(x,y-1,LR,1,0,x,y-1);
				}
			}
			if( y == 0 ){
				b3 = s_uping(x,y,1,breakwall,0,ssx,ssy);
			}
			
		}
		
		if( LR == 1 ){
			
			if( y+1 < M && s[x][y+1] == '.'){
				c1 = s_uping(x,y+1,LR,breakwall,0,ssx,ssy);
			}
			if( y+1 < M && s[x][y+1] == '#'){
				if(breakwall == 0){
					c2 = s_uping(x,y+1,LR,1,0,x,y+1);
				}
			}
			if( y == M-1 ){
				c3 = s_uping(x,y,0,breakwall,0,ssx,ssy);
			}
			
		}
	}
	sss[x][y][LR][breakwall] = -1;
	/*int check1=0,check2=0,check3=0;
	if(a1==1 || a2==1 || b1==1 || b2==1 || b3==1 || c1==1 || c2==1 || c3==1){
		check1 = 1;
	}
	if(a1==2 || a2==2 || b1==2 || b2==2 || b3==2 || c1==2 || c2==2 || c3==2){
		check2 = 1;
	}
	/*if(a1==3 || a2==3 || b1==3 || b2==3 || b3==3 || c1==3 || c2==3 || c3==3){
		check3 = 1;
	}
	if(check3 || (check1&&check2) ){
		arr[x][y][LR][breakwall] = 3;
		return arr[x][y][LR][breakwall];
	}*/
	/*if(check1){
		arr[x][y][LR][breakwall] = 1;
		return arr[x][y][LR][breakwall];
	}
	if(check2){
		arr[x][y][LR][breakwall] = 2;
		return arr[x][y][LR][breakwall];
	}*/
	
	
	
	return sss[x][y][LR][breakwall];
	
}

int main(){
	int count1 = 0,count2 = 0;
	cin >> M >> N;
	string sss;
	for(int i=0;i<M;i++){
		sss.push_back('.');
	}
	for(int i=0;i<N*2;i+=2){
		s[i] = sss;
		cin >> s[i+1];
	}
	
	/*for(int i=0;i<N*2;i++){
		cout << i << " " << s[i] << "\n";
	}*/
	
	N *= 2;
	for(int i=0;i<M;i++){
		//printf("0 %d LR = %d\n",i,0);
		int check = 0;
		check = dfs(0,i,0,0);
		if(check==1){
			count1++;
			count2++;
		}
		/*else{
			printf("0 %d LR = %d \n",i,0);
		}*/
		/*if(check==2){
			
			count2++;
		}*/
		/*if(check==3){
			count1++;
			count2++;
		}*/
		//
		//printf("0 %d LR = %d\n",i,1);
		check = 0;
		check = dfs(0,i,1,0);
		if(check==1){
			count1++;
			count2++;
		}
		/*else{
			printf("0 %d LR = %d\n",i,1);
		}*/
		/*if(check==2){
			
			count2++;
		}*/
		/*if(check==3){
			count1++;
			count2++;
		}*/
		
	}
	/*for(int i=0;i<M;i++){
		printf("%d --- LR = 0 = %d , LR = 1 = %d\n",i,arr[0][i][0][0],arr[0][i][1][0]);
	}*/
	//cout << count1 << " " << count2 << "\n";
	//cout << "print\n";
	/*for(int i=0;i<M;i++){
		cout << i << ".....";
		if(s[N-1][i]=='$'){
			//printf("LLL.......................\n");
			s_uping(N-2,i,0,0,1,-1,-1);
			//printf("RRR.......................\n");
			s_uping(N-2,i,1,0,1,-1,-1);
			
		}
		
		cout << maxx << "\n";
	}*/

	//sort(savetotest.begin(), savetotest.end() );
	int supermaxx = -1;
	//for(int iiii=ipos-1;iiii>=0;iiii--){
	for(int iiiii=1;iiiii<N;iiiii+=2){
		for(int jjjjj=0;jjjjj<M;jjjjj++){
		if(s[iiiii][jjjjj]!='#')	continue;
		
		for(int xi=0;xi<N;xi++){
			for(int xj=0;xj<M;xj++){
				for(int xLR=0;xLR<1;xLR++){
					for(int bw=0;bw<1;bw++){
						arr[xi][xj][xLR][bw] = 0;
					}
				}
			}
		}
		
		//int ppos = savetotest[iiii].second;
		//s[pos[ppos].first][pos[ppos].second] = '.';
		s[iiiii][jjjjj] = '.';
		//printf("change %d %d\n",pos[ppos].first,pos[ppos].second);
		/*printf("delete %d %d\n",iiiii,jjjjj);
		for(int i=0;i<N*2;i++){
			cout << i << " " << s[i] << "\n";
		}
		for(int xi=0;xi<N;xi++){
			for(int xj=0;xj<M;xj++){
				for(int xLR=0;xLR<1;xLR++){
					printf("%d",arr[xi][xj][xLR][0]);
				}
			}
		}printf("\n");*/
			
		
		
		int ncount1=0,ncount2=0;
		for(int i=0;i<M;i++){
			//printf("0 %d LR = %d\n",i,0);
			int check = 0;
			check = dfs(0,i,0,0);
			if(check==1){
				ncount1++;
				ncount2++;
			}

			check = 0;
			check = dfs(0,i,1,0);
			if(check==1){
				ncount1++;
				ncount2++;
			}
			
		}
		supermaxx = max(supermaxx,ncount1);
		//s[pos[ppos].first][pos[ppos].second] = '#';
		s[iiiii][jjjjj] = '#';
		}	
	}
	
		
	cout << count1 << " " << supermaxx << "\n";
	/*for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%d",arr[i][j][0][0]);
		}cout << "\n";
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%d",arr[i][j][1][0]);
		}cout << "\n";
	}*
	
	/*for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%d",visit[i][j][0]);
		}cout << "\n";
	}
	cout << "\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%d",visit[i][j][1]);
		}cout << "\n";
	}*/
}

/*
12 4 
#####.###.## 
###.#####.## 
#.####.##### 
@##$########

3 3
.#.
###
#$#

3 3
...
...
#$#

12 4 
#####.###.## 
###.#####.## 
#.####.##.## 
@##$#####@## 

50 50
.#.##..####.##.######.#.##################.#######
##.###.######..#############.########.#.#.####.###
###.##.##.#.########.#######.#.####.##########.###
######..###.#######..#..##################..######
###.###.##.###..##########.###..####.####.########
#.#########.######..####.#.##.################.##.
###.#####.###.#.####..##############.#####.#####.#
.#########.##.#.########..###.#####.#####.##.#####
#.#####.#####.#####..#.#.#####...#################
#####.######.##..######..###.###.#################
#######.#.##.#####.#####.###.#####.##.#.##########
#..####################.##.########.##.########.##
######..#.#.#.###.##.###.####.###########.########
##.###..###############.####..#######.#####..#####
###.####.#######.###.#####.#.##.######.######..###
#####.########.######.#.##########.##.#######.###.
.####.#.##.#####.#######.###.############.#####.##
.####.########.#####.#######.#######.##.###.##.#.#
##########.####.########..###.############..####.#
#..###########.##.####.#.#######..##############.#
#####.##.###..#######.##.#############.##.###.####
##.####.#########.######...#########.#.###########
#.##.#############.######..#.###.######..###.#####
#######.##.#####.######.#####.########.##..###.##.
##########.#.#.#########...####.######.##.########
..########..#########.######.###.############.###.
#####.#..##############..########.###.####.##.####
#.##.#.####.######.#################..#####.####.#
#.###########.##############.##...#.##.########.##
###.#######.##########..###########.####.##.##.##.
#.##.######..###.#############.###.##.##.######.##
##.############.##.#####.#########.##..#.######.##
.##.##.###.###.####.######.##########.####.#.#####
.#.#################.#####.#..###.####.###.####.##
####.#######.#.#####..##.####.###########.##..####
.###.##########.##.####.######..##########.#.###.#
####.#.###.###.#.#.###########.####.#####.#####.##
##..###.#######.#################..#####.#.######.
#####..#####.#.####.##.############.#.###.########
.########.##.##########.#..########..#############
#######.######.#.####.##..####.##################.
#######..####.###.####.######.#####..#####.##.####
######.##########...######.#######.####.###.######
####.#######.#####.#########..####.####.##.#####.#
########..##########.##.#######.#.#.###.##.#.#####
######.#.########..####.###.######.#.###########.#
#######.##########.#.###.####.##.#############.#.#
#####.#.####.###########.#######.#####.###.######.
.#####.######.####.########..############.##.###.#
#####@######$#####$##@$@##$###############$##@####
*/
