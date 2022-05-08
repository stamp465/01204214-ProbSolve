#include<bits/stdc++.h>
using namespace std;

int arr[150];
int nub[150];
int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0,x,y;i<M;i++){
		cin >> x >> y;
		nub[x]++;
		if(nub[x]>5)	arr[x] = 0;
		else{
			arr[x] = max(arr[x],y);
		}
	}
	int sum=0;
	for(int i=1;i<=N;i++)	sum+=arr[i];
	cout << sum;
}
