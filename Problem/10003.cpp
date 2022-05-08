#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int arr[10000];

int check(int i,int j){
    if(abs(i-j)==1)	return 0;
    if(dp[i][j]==-10){
    	int minn = 1e9;
    	for(int k=i+1;k<j;k++){
    		minn = min( minn, check(i,k)+check(k,j)+( arr[j]-arr[i] ) );
		}
		dp[i][j] = minn;
	}
	return dp[i][j];
}

int main(){
    while(1){
        int n,l;
        cin >> l;
        if(l==0)	break;
        for(int i=0;i<100;i++){
        	for(int j=0;j<100;j++){
        		dp[i][j] = -10;
			}
		}

        arr[0]=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        arr[n+1] = l;
        
        cout << "The minimum cutting is " << check(0,n+1) << ".\n";
    }
}
