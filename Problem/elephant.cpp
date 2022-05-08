#include<bits/stdc++.h>
using namespace std;
int N,ans=0;
int arr[150000],dp[150000];
main(){
	
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i];
		if(i<2) continue;
		dp[i] = max( arr[i] + dp[i-3] , dp[i-1] );
		ans = max(ans,dp[i]);
		
	}
	cout << ans;
}

/*
12
1
2
5
4
3
0
6
1
2
7
2
1

*/
