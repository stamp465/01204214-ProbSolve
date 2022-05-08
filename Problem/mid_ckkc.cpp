#include<bits/stdc++.h>
using namespace std;

int visit[5000];
vector<int> vec;

int main(){
	for(int i=0; i<=2557;i++){
		vec.push_back(-1);
	}
	for(int i=2558; i<=3000;i++){
		vec.push_back(i%2);
	}
	
	int X,nub=0;
	cin >> X;
	int ans = vec[X];
	while(1){
		int y;
		cin >> y;
		if(y==0)	break;
		if(y >= 2558 && y <= X){
	        if(ans==1)	ans=0;
	        else if(ans==0)	ans=1;
    	}
	}
	if(ans==0)	cout << "K";
	if(ans==1)	cout << "C";
}
