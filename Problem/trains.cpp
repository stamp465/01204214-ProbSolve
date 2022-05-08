#include<bits/stdc++.h>
using namespace std;

list<int> l[305000];

int main(){
	int N;
	cin >> N;
	
	for(int i=0;i<N;i++){
		char a[5];
		cin >> a;
		if(a[0]=='N'){
			int X,ii;
			cin >> X >> ii;
			l[ii].emplace_back(X);
		}
		if(a[0]=='M'){
			int ii,jj;
			cin >> ii >> jj;
			l[jj].splice(l[jj].end(),l[ii]);
		}
	}
	
	for(int i=1;i<=100000;i++){
		if( !l[i].empty() ){
			for(auto it:l[i]){
				cout << it << endl;
			}
		}
	}
	
	
}
