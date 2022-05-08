#include<bits/stdc++.h>
using namespace std;

int sum, par[100000], n, m;
set<tuple<int, int, int>> vec;

int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

int main(){
	cin >> n >> m;
	
	for(int i = 0, u, v, w; i < m; ++i) {
		sum = 0;
		for(int j = 1; j <= n; ++j) par[j] = j;
        scanf("%d %d %d", &u, &v, &w);
        //sum += w;
        vec.insert(make_tuple(w, u, v) );
        
	    for(auto edge : vec) {
	        int w, u, v; tie(w, u, v) = edge;
	        int a = find(u), b = find(v);
	        //printf("now = %d %d %d\n",u,v,w);
	        if(a != b) {
	            par[a] = b;
	            sum += w;
	            //cout << w << "\n";
	        }
	    }
	    for(int j=1;j<=n;j++){
	    	if( find(1) != find(j) ){
	    		sum = -1;
	    		break;
			}
		}
	    
	    printf("%d\n", sum);
        
    }
}

/*
4 6
1 2 10
1 3 8
3 2 3
1 4 3
1 3 6
2 1 2

*/
