#include<bits/stdc++.h>
using namespace std;

list<int> lis;
list<int>::iterator  it;
int N,M;

int main(){
	cin >> N >> M;
	for(int i=0,x;i<N;i++){
		cin >> x;
		lis.push_back(x);
	}
	it = lis.begin();
	for(int i=0;i<M;i++){
		int T;
		cin >> T;
		if(T==1){
			it = lis.begin();
		}
		else if(T==2){
			it++;
			if(it==lis.end()) it = lis.begin();
		}
		else if(T==3){
			int xx;
			cin >> xx;
			lis.insert(it,xx); 
		}
		else if(T==4){
			int xx;
			cin >> xx;
			it++;
			lis.insert(it,xx); 
			it--;
			it--;
		}
	}
	for(auto i:lis){
		cout << i << "\n";
	}
}
