#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m;
int sum, par[N];
set<int> s;

int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) par[i] = i;
    for(int i = 1,v; i <= n; ++i) {
        scanf("%d",&v);
        int a = find(i), b = find(v);
        if(a != b) {
	        par[a] = b;
	    }
    }
    for(int i = 1; i <= n; ++i) {
    	s.insert(find(i));
	}
	printf("%d\n",s.size());
}
