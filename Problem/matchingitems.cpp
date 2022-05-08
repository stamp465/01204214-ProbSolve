#include<bits/stdc++.h>
using namespace std;
long long N,M;
vector<long long>vec;
int main(){
	cin >> N >> M;
	for(long long i=0;i<N;i++){
		long long a;
		cin >> a;
		vec.emplace_back(a);
	}
	for(long long j=0;j<M;j++){
		long long want,plus;
		cin >> want >> plus;
		auto it = upper_bound(vec.begin(),vec.end(),vec[want-1]+plus);
		//cout << *it << "....";
		cout << it - vec.begin() << "\n";
	}
}
/*
6 6
10 30 50 55 100 130
1 40
3 49
5 10
*/
