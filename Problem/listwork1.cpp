#include<bits/stdc++.h>
using namespace std;

list<int> l;

int main(){
	int m;
	char cmd[5];
	
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> cmd;
		if(cmd[0] == 'I'){
			int x;
			cin >> x;
			l.emplace_front(x);
		}
		else if(cmd[0] == 'A'){
			int x;
			cin >> x;
			l.emplace_back(x);
		}
		else{
			int x;
			cin >> x;
			int i=1;
			for(auto it = l.begin(); it != l.end(); it++,i++){
				if(i==x){
					it = l.erase (it);
				}
			}
		}
	}
	for(auto it:l){
		cout << it << '\n';
	}
}
