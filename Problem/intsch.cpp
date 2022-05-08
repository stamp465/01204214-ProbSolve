#include<bits/stdc++.h>
using namespace std;

pair<int,int> p[1000000];

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p[i].second >> p[i].first;
	}
	int now=0;
	int countt=1;
	sort(p,p+n);
	for(int i=0;i<n;i++){
		if( p[now].first <= p[i].second ){
			now = i;
			countt++;
		}
	}
	cout << countt;
}
