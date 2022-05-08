#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int>	mapp;
int arr[500000];
int N,M;

int main(){
	cin >> N >> M;
	for(int i=0,x;i<N;i++){
		cin >> x;
		for(int j=0;j<i+1;j++){
			arr[j] += x;
			//cout << arr[j] << " ";
			mapp[ arr[j] ] = 1;
		}//cout << endl;
	}
	for(int i=0,y;i<M;i++){
		cin >> y;
		if( mapp[y]==1 )	cout << "Y";
		else				cout << "N";
	}
}
