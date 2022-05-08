#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,a,b,r,c=0;
	cin >> N >> a >> b >> r;
	while(N--){
		int x,y;
		cin >> x >> y;
		if( abs(a-x)*abs(a-x) + abs(b-y)*abs(b-y) <= r*r) c++;
	}
	cout << c;
}
