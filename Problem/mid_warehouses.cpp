#include<bits/stdc++.h>
using namespace std;

int N,M,K;
int par[200000];
vector<tuple<int, int, int>> vec;
int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

int main(){
	cin >> N >> M >> K;
	for(int i = 1; i <= N; ++i) par[i] = i;
    for(int i = 1, u, v; i <= M; i++) {
        scanf("%d %d", &u, &v);
        vec.emplace_back(1, u, v);
    }

    for(auto edge : vec) {
        int w, u, v; tie(w, u, v) = edge;
        int a = find(u), b = find(v);
        if(a != b) {
            par[a] = b;
        }
    }
    
    for(int i = 1, u, v; i <= K; i++) {
        scanf("%d %d", &u, &v);
        int a = find(u), b = find(v);
        if(a != b) {
            cout << "0\n";
        }
        else	cout << "1\n";
    }
}
