#include<bits/stdc++.h>
using namespace std;

int arr[300000];

int main(){
	arr[0] = 1;
	arr[1] = 1;
	int N,M,nub=0;
    cin >> N >> M;
	for (int i = 2; i <= M; i++){
        if (arr[i] == 0){
            for (int j = i+i; j <= M; j += i)	arr[j] = 1;
        }
    }
    
    for(int i=N;i<=M;i++){
    	if(arr[i]==0){
    		if(arr[i+2]==0 && i+2 <= M)	nub++;
    		//cout << i << " " << nub << "\n";
		}
	}
	cout << nub << endl;

	

}
