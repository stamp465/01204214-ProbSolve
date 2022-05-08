#include<bits/stdc++.h>
using namespace std;

list<int> l[305000];
int par[305000];

int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

int main(){
	int N;
	cin >> N;
	
	for(int i=1;i<=N;i++){
		l[i].emplace_back(i);
		par[i] = i;
	}
	
	for(int i=1;i<N;i++){
		int x,y;
		cin >> x >> y;
		int pary = find(y);
		for(auto it = l[pary].begin(); it != l[pary].end(); it++){
			if(*it==y){
				it++;
				l[pary].splice(it, l[x]);
			}
		}
		par[x] = y;
		
		for (int j=1;j<=N;j++)
        {   
            cout << par[j] << "..........";
        }cout << endl;
		
		if(i==N-1){
			for(auto it:l[pary]){
				cout << it << ' ';
			}cout << endl;
		}
		
	}
	
}

/*
8 
7 4 
3 5 
5 4 
8 1 
2 8 
1 6
4 8
*/
