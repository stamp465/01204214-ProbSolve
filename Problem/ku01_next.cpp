#include<bits/stdc++.h>
using namespace std;

int to[100005];
int visit[100005];
int maxfem = 0;

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int c;
		scanf("%d",&c);
		to[i] = c;
	}
	for(int i=1;i<=N;i++){
		if(visit[i]==1)	continue;
		int go = i;
		int nub = 0;
		while(1){
			nub++;
			if(go==i && visit[i]==1)	break;
			visit[go] = 1;
			go = to[go];
		}
		//printf("---%d %d\n",i,nub);
		if(nub > maxfem)	maxfem = nub;
	}
	printf("%d",maxfem-1);
}
