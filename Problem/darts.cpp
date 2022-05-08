#include<bits/stdc++.h>
using namespace std;

float area[8];
int main(){
	for(int i=2,j=5;j>0;j--,i+=2){
		area[j] = (float)i;
	}
	int N,sc=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		float x,y;
		scanf("%f %f",&x,&y);
		for(int j=5;j>0;j--){
			//printf("%f %f\n",sqrt(x*x+y*y),area[j]);
			if( sqrt(x*x+y*y)<=area[j] ){
				sc += j;
				break;
			}	
		}
	}
	printf("%d",sc);
}
