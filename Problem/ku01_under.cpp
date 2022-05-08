#include<bits/stdc++.h>
using namespace std;
int maxx = -1e9;
int arr[1000];
int main(){
	int L,N;
	cin >> L >> N;
	for(int i=0;i<N;i++){
		int st,en;
		cin >> st >> en;
		for(int j=st*2+1;j<en*2;j++){
			arr[j]++;
			maxx = max(maxx,arr[j]);
		}
	}
	cout << maxx << '\n';
}
