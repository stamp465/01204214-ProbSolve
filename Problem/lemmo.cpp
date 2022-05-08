#include<bits/stdc++.h>
using namespace std;

int N,M;
string s[10000];
int can111 = 0,can222=0;
// left 0 right 1
// not 0 go 1

int bfs(int x,int y,int LR){
	queue< vector<int> > q;
	q.push({x,y,LR,0});	
	while(!q.empty()){
		vector<int> now = q.front();
		q.pop();
		
		if( now[0] == N-2 ){
			int can1=0,can2=0;
			if(now[2]==0){
				//printf("%d %d %d %d\n",now[0],now[1],now[2],now[3]);
				for(;now[1]>=0;now[1]--){
					if(s[now[0]+1][now[1]] == '@'){
						if(now[3]==1)   can1 = 2;
						if(now[3]==0)	can2 = 2;
						break;
					}
					if(s[now[0]+1][now[1]] == '$'){
						if(now[3]==1)   can1 = 1;
						if(now[3]==0)	can2 = 1;
						break;
					}
				}
				if(can1==0 && can2==0){
					for(;now[1]<M;now[1]++){
						if(s[now[0]+1][now[1]] == '@'){
							if(can1==0)	if(now[3]==1)   can1 = 2;
							if(can2==0) if(now[3]==0)	can2 = 2;
							break;
						}
						if(s[now[0]+1][now[1]] == '$'){
							if(can1==0) if(now[3]==1)   can1 = 1;
							if(can2==0) if(now[3]==0)	can2 = 1;
							break;
						}
					}
				}
				//printf("can2 = %d can1 = %d\n",can2,can1);
				if(can1==1)	can111 = 1;
				if(can2==1)	can222 = 1;
			}
			else{
				for(;now[1]<M;now[1]++){
					if(s[now[0]+1][now[1]] == '@'){
						if(now[3]==1)   can1 = 2;
						if(now[3]==0)	can2 = 2;
						break;
					}
					if(s[now[0]+1][now[1]] == '$'){
						if(now[3]==1)   can1 = 1;
						if(now[3]==0)	can2 = 1;
						break;
					}
				}
				if(can1==0 && can2==0){
					for(;now[1]>=0;now[1]--){
						if(s[now[0]+1][now[1]] == '@'){
							if(can1==0) if(now[3]==1)   can1 = 2;
							if(can2==0) if(now[3]==0)	can2 = 2;
							break;
						}
						if(s[now[0]+1][now[1]] == '$'){
							if(can1==0) can1 = 1;
							if(can2==0) if(now[3]==0)	can2 = 1;
							break;
						}
					}
				}
				if(can1==1)	can111 = 1;
				if(can2==1)	can222 = 1;
			}
		}
		else{
			if(now[2]==0){
				if( s[ now[0] + 1 ][ now[1] ] == '.' ){
					//cout << "s1\n";
					int goto1 = now[0] + 1;
					int goto2 = now[1];
					q.push({goto1,goto2,0,now[3]});
				}
				else{
					//cout << "s2\n";
					if( now[1]-1 >= 0){
						if( s[ now[0] ][ now[1]-1 ] == '.'){
							int goto1 = now[0];
							int goto2 = now[1] - 1;
							q.push({goto1,goto2,0,now[3]});
						}
					}
					if( now[1]-1 < 0){
						int goto1 = now[0];
						int goto2 = now[1];
						q.push({goto1,goto2,1,now[3]});
					}
					/*if( s[now[0]][now[1]-1] == '#' && now[3]==0){
						int goto1 = now[0];
						int goto2 = now[1]-1;
						q.push({goto1,goto2,0,1});
						
					}*/
					if( s[now[0]+1][now[1]] == '#' && now[3]==0){
						int goto1 = now[0]+1;
						int goto2 = now[1];
						q.push({goto1,goto2,0,1});
						
					}
				}
				
			}
			else{
				if( s[ now[0] + 1 ][ now[1] ] == '.' ){
					//cout << "s1\n";
					int goto1 = now[0] + 1;
					int goto2 = now[1];
					q.push({goto1,goto2,1,now[3]});
				}
				else{
					//cout << "s2\n";
					if( now[1]+1 < M){
						if( s[ now[0] ][ now[1]+1 ] == '.'){
							int goto1 = now[0];
							int goto2 = now[1] + 1;
							q.push({goto1,goto2,1,now[3]});
						}
					}
					if( now[1]+1 >= M){
						int goto1 = now[0];
						int goto2 = now[1];
						q.push({goto1,goto2,0,now[3]});
					}
					/*if( s[now[0]][now[1]+1] == '#' && now[3]==0){
						int goto1 = now[0];
						int goto2 = now[1]+1;
						q.push({goto1,goto2,1,1});
						
					}*/
					
					if( s[now[0]+1][now[1]] == '#' && now[3]==0){
						int goto1 = now[0]+1;
						int goto2 = now[1];
						q.push({goto1,goto2,1,1});
						
					}
				}
			}
		}
	}
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
	/*
	for(int i=0;i<N*2;i++){
		cout << s[i] << "\n";
	}*/	
	N *= 2;
	for(int i=0;i<M;i++){
		//printf("start 0 %d \n",i);
		can111 = 0;
		can222 = 0;
		bfs(0,i,0);
		if(can111==1){
			count2 ++ ;
		}
		if(can222==1)	count1 ++ ;
		
		can111 = 0;
		can222 = 0;
		bfs(0,i,1);
		if(can111==1){
			count2 ++ ;
		}
		if(can222==1)	count1 ++ ;
		
	}
	cout << count1 << " " << count2 << "\n";
	
}

/*
12 4 
#####.###.## 
###.#####.## 
#.####.##### 
@##$########

12 4 
#####.###.## 
###.#####.## 
#.####.##.## 
@##$#####@## 
*/
