#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m;
double sum=0;
int par[N], timee[N];
int x[N],y[N];
vector<tuple<double, int, int>> vec;

int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)	{
    	scanf("%d %d",&x[i],&y[i]);
    	for(int j = 1; j < i; j++){
    		int xx = x[i] - x[j];
    		int yy = y[i] - y[j];
    		double distance = double( sqrt(  xx*xx + yy*yy  ) );
    		vec.emplace_back(distance, i, j);
		}
	}
	
	for(int i = 0; i <= n; ++i) par[i] = i;
    sort(vec.begin(), vec.end());
	
	for(auto edge : vec) {
        double w;
		int u, v; 
		tie(w, u, v) = edge;
        //cout << w << " " << u << " " << v << endl;
        
        int a = find(u), b = find(v);
        if(a != b) {
            par[a] = b;
            sum += w;
            n--;
            if(n==2)	break;
            //cout << w << "\n";
        }
        
    }
	printf("%.5f\n", sum);

    
}
