#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m;
int sum,all, par[N];
vector<tuple<int, int, int>> vec;

int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

int main() {
	while(1){
		scanf("%d %d", &n, &m);
		if(n==0&&m==0)	break;
		sum = 0;
		all = 0;
		vec.clear();
	    for(int i = 0; i < n; ++i) par[i] = i;
	    for(int i = 0, u, v, w; i < m; ++i) {
	        scanf("%d %d %d", &u, &v, &w);
	        all += w;
	        vec.emplace_back(w, u, v);
	    }
	    sort(vec.begin(), vec.end());
	    //reverse(vec.begin(), vec.end());
	    for(auto edge : vec) {
	        int w, u, v; tie(w, u, v) = edge;
	        int a = find(u), b = find(v);
	        if(a != b) {
	            par[a] = b;
	            sum += w;
	            //cout << w << "\n";
	        }
	    }
	    printf("%d\n", all - sum);
	}
    
}

/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0
*/
