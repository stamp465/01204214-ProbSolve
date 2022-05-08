#include<bits/stdc++.h>
using namespace std;

int check(int a,int b){
	return min( abs(a-b), 26-abs(a-b) );
}

string s;

int dp[2000][50][50];

int main(){
	int T;
	cin >> T;
	for(int x=0;x<T;x++){
		int minn = 1e9;
		cin >> s;
		int N = s.size();
		for(int i=0;i<N;i++){
			for(int j=0;j<26;j++){
				for(int k=0;k<26;k++){
					dp[i][j][k] = 1e9;
				}
			}
		}
		
		dp[0][ s[0] - 'A' ][0] = check(s[0] - 'A',0);
		dp[0][0][ s[0] - 'A' ] = check(s[0] - 'A',0);
		
		if(N==1){
			cout << dp[0][ s[0] - 'A' ][0] << "\n";
			continue;
		}
		for(int i=1;i<N;i++){
			for(int j=0;j<26;j++){
				for(int k=0;k<26;k++){
					if( dp[i-1][j][k] == 1e9 )	continue;
					
					//printf("now i j k = %d %d %d ...\t ",i,j,k);
					
					
					int a = check(s[i] - 'A',j);
					dp[i][s[i] - 'A'][k] = min(dp[i-1][j][k] + a ,  dp[i][s[i] - 'A'][k] );
					
					int b = check(s[i] - 'A',k);
					dp[i][j][s[i] - 'A'] = min(dp[i-1][j][k] + b ,  dp[i][j][s[i] - 'A'] );
					
					//printf("dp[i-1] a b = %d %d %d ...\t",dp[i-1][j][k],a,b);
					//printf("dp[%d][%d] = %d and ", s[i] - 'A',k,dp[i][s[i] - 'A'][k] );
					//printf("dp[%d][%d] = %d\n", j,s[i] - 'A',dp[i][j][s[i] - 'A'] );
					
					if(i==N-1)	{
						minn = min(minn,dp[i][s[i] - 'A'][k]);
						minn = min(minn,dp[i][j][s[i] - 'A']);
					}
					
				}
			}
			
		}
		
		cout << minn << "\n";
	}
}
