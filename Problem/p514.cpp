#include<bits/stdc++.h>
using namespace std;

int main(){
	while(1){
		
		int n;
		cin >> n;
		if(n==0)	break;
		
		while(1){
			stack<int> st;
			int arr[n];
			cin >> arr[0];
			if(arr[0]==0){
				cout << '\n';
				break;
			}
			//cout << "11111\n";
			for(int i=1;i<n;i++){
				cin >> arr[i];
			}
			//cout << "22222\n";
			int check = 0;
			for(int i=1;i<=n;i++){
				st.push(i);
				while( !st.empty() && st.top()==arr[check] ){
					check++;
					st.pop();
				}
				//cout << i << endl;
			}
			if(st.empty())	cout << "Yes" << "\n";
			else 			cout << "No" << "\n";
		}
		
	}
}
