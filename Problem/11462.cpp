#include<bits/stdc++.h>
using namespace std;

int arr[2000050];

int main(){
	while(1){
		int n;
		cin >> n;
		if(n==0)	break;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			if (i > 0)
	        	printf(" ");
	      	printf("%d", arr[i]);
		}printf("\n");
	}
}

/*
5
3 4 2 1 5
5
2 3 2 3 1
0
*/
