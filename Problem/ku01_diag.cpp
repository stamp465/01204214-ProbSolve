#include<bits/stdc++.h>
using namespace std;
long long x,y;
long long nub=0;
vector<pair<long long,long long>> vec;
vector<long long>	xnxx;
vector<long long>	ynyy;
int main(){
	long long N;
	long long tox=0,toy=0;
	cin >> N;
	for(long long i=0;i<N;i++){
		cin >> x >> y;
		long long xx = x+y;
		long long yy = y-x;
		vec.emplace_back(xx,yy);
		xnxx.emplace_back(xx);
		ynyy.emplace_back(yy);
		tox += xx;
		toy += yy;
	}
	
	/*cout << "NEW...\n";
	for(auto v:vec){
		cout << v.first << " " << v.second << "\n";
	}*/
	
	sort(vec.begin(),vec.end());
	sort(xnxx.begin(),xnxx.end());
	sort(ynyy.begin(),ynyy.end());
	
	long long medx = xnxx[N/2];
	if(N%2==0)	medx = (xnxx[N/2]+xnxx[N/2-1])/2;
	long long medy = ynyy[N/2];
	if(N%2==0)	medy = (ynyy[N/2]+ynyy[N/2-1])/2;
	
	double avgx = ((double)tox)/(double)N;
	double avgy = ((double)toy)/(double)N;

	//cout << "Avg = " << avgx << " " << avgy << "\n";
	/*for(auto v:vec){
		//cout << abs(v.first - avgx) << " " << abs(v.second - avgy) << "\n";
		nub += abs(v.first - avgx) + abs(v.second - avgy);
	}
	cout << nub;
	*/
	
	
	
	pair<long long,long long> p = { avgx, avgy };
	auto it = upper_bound(vec.begin(), vec.end(), p );
	//cout << it->first << " " << it->second << "\n";
	//cout << medx << "..." << medy << "\n";
	for(auto v:vec){
		//cout << abs(medx - v.first) << " " << abs(medy - v.second) << "\n";
		nub += abs(medx - v.first) + abs(medy - v.second);
		//nub += abs(it->first - v.first) + abs(it->second - v.second);
	}
	cout << nub;
	
}

/*
4
1 1
5 5
6 6
3 3

6
1 1
2 3
4 4
5 3
4 1
7 3

6
1 1
1 4
2 2
2 4
2 6
2 8
*/
