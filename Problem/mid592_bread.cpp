#include<bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int,int> > vec;

int main(){
	int N,Q;
	cin >> N >> Q;
	for(int i=0;i<N;i++){
		int x,y,z;
		cin >> x >> y >> z;
		vec[x] = {y,z};
	}
	for(int i=0;i<Q;i++){
		int s;
		cin >> s;
		int save=-1;
		int maxx=1e9;
		for(int i=0;i<=5;i++){
			auto it = vec.find(s+i);
			if( it != vec.end() && vec[s+i].second != 0 ){
				if( vec[s+i].first < maxx ){
					maxx = vec[s+i].first;
					save = s+i;
				}
			}
			it = vec.find(s-i);
			if( it != vec.end() && vec[s-i].second != 0 ){
				if( vec[s-i].first < maxx ){
					maxx = vec[s-i].first;
					save = s-i;
				}
			}
		}
		if(save==-1)	{
			cout << "0\n";
			continue;
		}
		vec[save].second--;
		cout << vec[save].first << "\n";
	}
}
