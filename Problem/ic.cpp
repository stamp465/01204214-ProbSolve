#include<bits/stdc++.h>
using namespace std;

list<int> l;

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string a;
		int b;
		cin >> a;
		if(a=="ri"){
			cin >> b;
			l.emplace_back(b);
		}
		if(a=="li"){
			cin >> b;
			l.emplace_front(b);
		}
		if(a=="rr"){
			l.emplace_front(l.back());
			l.pop_back();
		}
		if(a=="lr"){
			l.emplace_back(l.front());
			l.pop_front();
		}
	}
	for(auto it:l){
		cout << it << '\n';
	}
}
