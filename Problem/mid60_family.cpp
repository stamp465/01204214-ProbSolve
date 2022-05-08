#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int main(){
	int N,M;
	cin >> N >> M;
	for(int i=2;i<=N;i++){
		int f;
		cin >> f;
		arr[i] = f;
	}
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		if(arr[a] == b)			printf("%d\n",b);
		else if(arr[b] == a)	printf("%d\n",a);
		else{
			int ff_a = a;
			int ff_b = b;
			int ch = 0;
			if(ch==0)	while(1){
				if(ff_a==1)	break;
				ff_a = arr[ff_a];
				if(ff_a==b)	{
					printf("%d\n",b);
					ch = 1;
					break;
				}
			}
			if(ch==0)	while(1){
				if(ff_b==1)	break;
				ff_b = arr[ff_b];
				if(ff_b==a){
					printf("%d\n",a);	
					ch = 1;
					break;
				}
			}
			if(ch==0)	printf("-1\n");	
		}
	}
}
/*
4 3
1
4
1
4 1
3 2
4 3

10 6
1
9
9
9
4
1
7
1
7
6 4
4 9
6 1
9 6
4 7
10 7
*/
