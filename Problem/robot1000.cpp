#include<bits/stdc++.h>
using namespace std;

string str;
int main(){
	int x=0,y=0;
	cin >> str ;
	for(int i=0;i<str.length();i++){
		if(str[i] == 'N'){
			x+=0;
			y+=1;
		}
		if(str[i] == 'W'){
			x+=-1;
			y+=0;
		}
		if(str[i] == 'S'){
			x+=0;
			y+=-1;
		}
		if(str[i] == 'E'){
			x+=1;
			y+=0;
		}
		if(str[i] == 'Z'){
			x=0;
			y=0;
		}
	}
	printf("%d %d",x,y);
}
