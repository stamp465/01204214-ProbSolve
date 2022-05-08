#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, P, W;
		cin >> N;
		int dp[100];
		for(int i=0;i<100;i++)	dp[i] = 0;
		for(int i=0;i<N;i++) {
			cin >> P >> W;
			for(int j=51;j>=W;j--){
				dp[j] = max( dp[j],dp[ j - W ] + P );
				//printf("j = %d %d.... %d\n",j,W,dp[j]);
			}
		}
		
		/*for(int j=0;j<51;j++){
			
		}*/
		
		int pe,w_p,ans=0;
		cin >> pe;
		while(pe--) {
			cin >> w_p;
			ans += dp[w_p];
		}
		cout << ans << "\n";
	}
    return 0;
}
