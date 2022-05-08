#include<bits/stdc++.h>
using namespace std;
long long minn=1e9;
long long arr[100005];
int main(){
	long long N,K;
	scanf("%lld %lld",&N,&K);
	for(long long i=0;i<N;i++){
		scanf("%lld",&arr[i]);
		if(arr[i]<minn)	minn = arr[i];
	}
	long long nub = N;
	for(long long i=0;i<N;i++){
		if( minn*K / arr[i] == K )	continue;
		if( minn*K / arr[i] == K-1 && minn*K % arr[i] != 0)	continue;
		nub--;
	}
	printf("%lld",nub);
}
