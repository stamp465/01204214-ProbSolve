#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m;
int sum, par[N];
vector<tuple<int, int, int>> vec;

int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) par[i] = i;
    for(int i = 0,u,v; i < m; ++i) {
    	char q;
        scanf(" %c %d %d", &q, &u, &v);
        int a = find(u), b = find(v);
        if( q=='q' ){
        	if(a==b)	printf("yes\n");
        	else		printf("no\n");
		}
		else{
			if(a != b) {
	            par[a] = b;
	        }
		}
    }
    
}
