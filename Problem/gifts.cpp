#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,sum=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int c;
		scanf("%d",&c);
		if(c>0)	sum += c;
	}
	printf("%d",sum);
}
