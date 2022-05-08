#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > vec[5];
int main(){
	int N;
	cin >> N;
	for(int k=0,j=1;k<4;k++){
		int maxx = -1e9,savej=0;
		for(int i=1;i<=N;i++,j++){
			int pow;
			cin >> pow;
			if(pow>maxx){
				maxx = pow;
				savej = j;
			}
		}
		vec[k/2].emplace_back(maxx,savej);
	}
	sort(vec[0].begin(), vec[0].end());
	sort(vec[1].begin(), vec[1].end());
	if(vec[0][1].first > vec[1][1].first)	printf("%d %d %d %d\n",vec[0][1].second,vec[1][1].second,vec[0][0].second,vec[1][0].second);
	else									printf("%d %d %d %d\n",vec[1][1].second,vec[0][1].second,vec[0][0].second,vec[1][0].second);
}
/*
3
1
2
5
40
25
39
21
29
27
10
20
15

1
15
10
12
9

*/
