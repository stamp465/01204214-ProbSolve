#include<bits/stdc++.h>
using namespace std;

int arr[1000000];
int N,M,now=0;
int main(){
	cin >> N >> M;
	for(int i=1;i<=N;i++)	cin >> arr[i];
	for(int i=0,x;i<M;i++){
		cin >> x;
		now += x;
		if(arr[now]!=0)	now += arr[now];
		if(now>N)	now = N;
		if(now<0)	now = 0;
	}
	cout << now;
}
