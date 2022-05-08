#include<bits/stdc++.h>
using namespace std;

long long N,K;
long long C[10000],P[10000],W[10000];
long long data[10000];
long long minn = 1e9;

main(){
	cin >> N >> K;
	for(long long i=0;i<N;i++){
		cin >> C[i] >> P[i] >> W[i];
	}
	for(long long i=0;i<K;i++){
		cin >> data[i];
	}
	for(long long i=0;i<N;i++){
		long long sumnow = 0;
		long long usecar = 0;
		long long cost = 0;
		cost += C[i];
		for(long long j=0;j<K;j++){
			if( data[j] > W[i] ){
				//cout << data[j] << "..." << W[i] << "..." << i << "\n";
				usecar = 0;
				sumnow = 0;
				break;
			}
			sumnow += data[j];
			if( sumnow == W[i] ){
				sumnow = 0;
				usecar++;
			}
			else if( sumnow > W[i] ){
				sumnow = data[j];
				usecar++;
			}
		}
		if(sumnow!=0)	usecar++;
		cost += usecar*P[i];
		//cout << cost << endl;
		if(cost>C[i])	minn = min(minn,cost);
	}
	cout << minn;
}
