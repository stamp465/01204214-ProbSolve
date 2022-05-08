#include<bits/stdc++.h>
using namespace std;

int arr[5000];

int main(){
	int N;
	cin >> N;
	for(int i=1;i<=N;i++){
		int j;
		cin >> j;
		while(j--){
			int x,y;
			cin >> x >> y;
			for(int k=i;k<i+y;k++){
				arr[k] += x;
			}
		}
	}
	for(int i=1;i<=N;i++){
		cout << arr[i] << "\n";
	}
}
