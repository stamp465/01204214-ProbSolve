#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	int now = 1, nub = 0;
	scanf("%d %d %d",&a,&b,&c);
	while(1){
		nub++;
		now += b;
		now %= a;
		if(now == 1){
			printf("%d",nub);
			break;
		}
		if(now == c){
			printf("%d",nub+1);
			break;
		}
	}
}
