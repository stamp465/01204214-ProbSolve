#include<bits/stdc++.h>
using namespace std;

int arr[200100];
int dis[200100];
int maxx=0;
int main(){
	int N;
	cin >> N;
	
	for(int i=1;i<=N;i++){
		cin >> arr[i];
		if( arr[i] <= i ){
			dis[ i-arr[i] ]++;
		}
		else{
			dis[ (i-0)+(N-arr[i]) ]++;
		}
	}
	for(int i=1;i<=N;i++){
		maxx = max(dis[i],maxx);
	}
	cout << maxx;
}
