#include<bits/stdc++.h>
using namespace std;

int arr[120000];

int main(){
	int N,sum=0;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i];
		if(i>0 && arr[i-1] - arr[i] > 10){
			sum += min(700,(arr[i-1] - arr[i] )*10);
		}
	}
	cout << sum;
}
