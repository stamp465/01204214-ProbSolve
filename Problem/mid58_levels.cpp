#include<bits/stdc++.h>
using namespace std;

int N[2000][5];
int save[3];
int level = 1,x,y,z;
int willpass = 1;

int main(){
	int N1,M;
	cin >> N1 >> M;
	for(int i=1;i<N1;i++){
		cin >> N[i][0] >> N[i][1] >> N[i][2];
	}
	for(int i=0;i<M;i++){
		cin >> x >> y >> z;
		if( x >= N[willpass][0] ) save[0] = 1;
		if( y >= N[willpass][1] ) save[1] = 1;
		if( z >= N[willpass][2] ) save[2] = 1;
		if( save[0]+save[1]+save[2]==3 && willpass < N1 ){
			save[0] = 0;
			save[1] = 0;
			save[2] = 0;
			willpass++;
			level = willpass;
		}
	}
	cout << level;
}
