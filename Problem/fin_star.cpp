#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[100050][3];
int arr[100500][3];

main(){
	int N;
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> arr[i][1] >> arr[i][2];
		if(i==0){
			dp[0][0] = 0;
			dp[0][1] = arr[i][1];
			dp[0][2] = arr[i][2];
		}
		if(i>=1){
			dp[i][0] = max( dp[i-1][0] , dp[i-1][1] );
			dp[i][0] = max( dp[i][0] , dp[i-1][2] );
			
			dp[i][1] = max( dp[i-1][0] , dp[i-1][2] ) + arr[i][1];
			
			dp[i][2] = max( dp[i-1][0] , dp[i-1][1] ) + arr[i][2];
		}
	}
	int ans = 0;
	for(int i=0;i<3;i++){
		ans = max(ans,dp[N-1][i]);
	}
	cout << ans;
	
}
