#include<bits/stdc++.h>
using namespace std;

int N,M,K,ans=0;
int arr[250][250];
int save[250][250][250];

int dfs(int n,int m,int check){
	
	int a=0,b=0,c=0;
	
	if(n==N)	{
		//cout << save[n][m][check] << "\n";
		return save[n][m][check] = arr[n][m];
	}
	if(save[n][m][check]==0){
		a = dfs(n+1,m,check);
		if(check>0){
			if(m-1>=0)	b = dfs(n+1,m-1,check-1);
			if(m+1<M)	c = dfs(n+1,m+1,check-1);
		}
		return save[n][m][check] = max({a,b,c}) + arr[n][m];
		
	}
	else{
		return save[n][m][check];
	}
	
}

int main(){
	cin >> N >> M >> K;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<M;i++){
		ans = max(ans,dfs(0,i,K));
		
	}
	printf("%d\n",ans);
}
