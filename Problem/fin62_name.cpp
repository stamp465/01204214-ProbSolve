#include<bits/stdc++.h>
using namespace std;

string want,s;

int main(){
	cin >> want;
	cin >> s;
	
	int countt=0;
	int now=0;
	for(int i=0;i<s.length();i++){
		if( want[now] == s[i] ){
			now++;
			if(now==want.length()){
				countt++;
				now = 0;
			}
		}
		/*else if( want[0] == s[i] ){
			now = 1;
		}*/
	}
	cout << countt;
}

/*
pracha
thisisprachaheyproactivehappypramotechanochanell

stamp
dvfbpfl,stadcavvcmpsdadad
*/
