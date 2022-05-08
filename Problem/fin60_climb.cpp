#include <bits/stdc++.h>
using namespace std;

queue<tuple<int,int,int> > q;
string s[50];
int dis[50][50];
int nx,ny,nxxx,nyyy,nowdis,nextdis;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		cin >> s[i];
	    for(int j=0;j<m;j++){
	    	dis[i][j]=1e9;
	    }
	}
	q.push(make_tuple(0,n-1,0));
	dis[n-1][0]=0;
	

	int x[]={1,0,-1,0};
	int y[]={0,1,0,-1};
	
	while(!q.empty()){
	    tie(nowdis,nx,ny)=q.front();
	    q.pop();
		printf("%d %d %d\n",nowdis,nx,ny);
	    for(int c=0;c<=3;c++){
	        nxxx=nx+x[c];
	        nyyy=ny+y[c];
	        //printf("...%d %d...\n",nxxx,nyyy);
	        if(nxxx == -1 || nyyy == -1 || nxxx == n || nyyy == m || s[nxxx][nyyy] == 'X' )
	            continue;
			nextdis = nowdis;
	        if(c == 2)
	            nextdis += 5;
	        if(c == 1 || c == 3)
	            nextdis += 1;
	        if( nextdis >= dis[nxxx][nyyy] )
	        	continue;
	        dis[nxxx][nyyy] = nextdis;
	        q.push(tie(nextdis,nxxx,nyyy));
	    }
	}
	printf("%d",dis[0][m-1]==1e9 ? -1 : dis[0][m-1]);
}
