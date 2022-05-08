#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > vec;
int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		pair<int,int> xxnxx;
		int x,y;
		cin >> x >> y;
		xxnxx.first = x+10;
		xxnxx.second = y;
		vec.emplace_back(xxnxx);
	}
	sort(vec.begin(),vec.end());
	int now = 0;
	int minn = 0;
	for(int i=0;i<N;i++){
		now += vec[i].second;
		if( now > vec[i].first ){
			minn = max( now-vec[i].first , minn );
		}
		//cout << i << " " << now << "\n";
	}
	cout << minn*1000;
}
