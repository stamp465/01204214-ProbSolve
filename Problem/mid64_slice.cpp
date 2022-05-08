#include<bits/stdc++.h>
using namespace std;

int nub[600000];
int c[600000];
int countt=0;
int arr[500000];
int first[500000];
int N;
vector<int> vec;
int vec_max=0;

int main(){
	cin >> N;
	int before = 0;
	for(int i=1;i<=N;i++){
		cin >> arr[i];
		
		if( arr[i] > arr[i-1] ){
			for(int j=arr[i-1]+1; j<=arr[i] ; j++){
				first[ j ] = i;
			}
		}
		
		if( arr[i] < arr[i-1] ){
			for(int j=arr[i-1]; j>arr[i] ; j--){
				nub[ i-first[ j ] ]++;
			}
		}
		
		if(i==N){
			i=N+1;
			arr[i] = 0;
			if( arr[i] > arr[i-1] ){
				for(int j=arr[i-1]+1; j<=arr[i] ; j++){
					first[ j ] = i;
				}
			}
			
			if( arr[i] < arr[i-1] ){
				for(int j=arr[i-1]; j>arr[i] ; j--){
					nub[ i-first[ j ] ]++;
				}
			}
			
		}
		
	}
	
	
	
	for(int i=1;i<=500000;i++){
		if(nub[i]!=0)	countt++;
	}
	cout << countt << "\n";
	for(int i=1;i<=500000;i++){
		if(nub[i]!=0)	cout << i << " " << nub[i] << "\n";
	}
}
