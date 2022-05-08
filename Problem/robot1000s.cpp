#include<bits/stdc++.h>
using namespace std;
string s;
int arr[4],n;
int main(){
	cin >> s;
	int a = s.length();
	for(int i=0;i<a;i++){
		if(s[i]=='N')	arr[0]++;
		if(s[i]=='S')	arr[1]++;
		if(s[i]=='W')	arr[2]++;
		if(s[i]=='E')	arr[3]++;
	}
	cin >> n;
	for(int i=0;i<n;i++){
		if(arr[0] > arr[1] && arr[1] != 0){
			arr[1]--;
		}
		else if(arr[0] < arr[1] && arr[0] != 0){
			arr[0]--;
		}
		else if(arr[2] > arr[3] && arr[3] != 0){
			arr[3]--;
		}
		else if(arr[2] < arr[3] && arr[2] != 0){
			arr[2]--;
		}
		else{
			if(arr[0]!=0)		arr[0]--;
			else if(arr[1]!=0)	arr[1]--;
			else if(arr[2]!=0)	arr[2]--;
			else if(arr[3]!=0)	arr[3]--;
		}
	}
	cout << (abs(arr[0]-arr[1])+abs(arr[2]-arr[3]))*2 << endl;
}
