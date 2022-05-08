#include<bits/stdc++.h>
using namespace std;
string s,ans;
int swap_s[4][4] = { 	{0,1,2,3},
						{3,0,1,2},
						{2,3,0,1},
						{1,2,3,0}	};
int main(){
	cin >> s;
	int a = s.length();
	int status = 0;
	for(int i=0;i<a;i++){
		if(s[i]=='N'){			//0
			for(int j=0; j< swap_s[status][0];j++)	ans.push_back('R');
			ans.push_back('F');
			status = 0;
		}
		if(s[i]=='E'){			//1
			for(int j=0; j< swap_s[status][1];j++)	ans.push_back('R');
			ans.push_back('F');
			status = 1;
		}
		if(s[i]=='S'){			//2
			for(int j=0; j< swap_s[status][2];j++)	ans.push_back('R');
			ans.push_back('F');
			status = 2;
		}
		if(s[i]=='W'){			//3
			for(int j=0; j< swap_s[status][3];j++)	ans.push_back('R');
			ans.push_back('F');
			status = 3;
		}
		if(s[i]=='Z'){
			ans.push_back('Z');
			status = 0;
		}
	}
	cout << ans;
}
