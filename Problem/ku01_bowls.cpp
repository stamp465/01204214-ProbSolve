#include<bits/stdc++.h>
using namespace std;
int arr[305];
int main(){
	int N,max=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		arr[num]++;
		if(arr[num]>max)	max = arr[num];
	}
	printf("%d",max);
}
