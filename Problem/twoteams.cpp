#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> vec[150000];
vector<int> isin;
int iss[100005];
int par[150000];
int color[150000];
int visit[100005];
int vv=1;
int countt=0;
int check=1;

int findp(int u) { return par[u] = u == par[u] ? u : findp(par[u]); }

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		par[i] = i;
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		vec[x].emplace_back(y);
		vec[y].emplace_back(x);
		if(check==0)	continue;
		//printf(" be par -- %d %d  color %d %d\n",par[x],par[y],color[x],color[y]);
		if( color[y]!=0 ){
			swap(x,y);
		}
		if( color[x]!=0 ){
			if( color[y]!=0 ){
				if( findp(x) == findp(y) ){
					if( color[y] != 3-color[x] ){
						check = 0;
					}
				}
				else{
					if( color[y] == color[x] ){
						
						vv++;
						color[y] = 3-color[x];
						queue<int> qq;
						qq.push(y);
						while(!qq.empty()){
							int now = qq.front();
							qq.pop();
							visit[now] = vv;
							for( int i=0; i<vec[now].size(); i++ ){
								color[ vec[now][i] ] = 3-color[now];
								if( visit[vec[now][i]]==vv )
									qq.push(vec[now][i]);
							}
						}
						par[ findp( y ) ] = findp( x );
					}
					else{
						par[ findp( y ) ] = findp( x );
					}
					
				}
			}
			else{
				color[y] = 3-color[x];
				par[y] = findp(x);
			}
		}
		else{
			color[x] = 1;
			color[y] = 2;
			par[y] = findp(x);
		}
		//printf(" af par -- %d %d  color %d %d\n",par[x],par[y],color[x],color[y]);
		countt += check;
	}
	cout << countt;
}
