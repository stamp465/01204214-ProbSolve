#include<bits/stdc++.h>
using namespace std;
vector<int> vec,rvec;
int main(){
	int N,M,minn=1e9;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		if(num<minn) minn = num;
		vec.emplace_back(minn);
		rvec.emplace_back(minn);
	}
	reverse(rvec.begin(),rvec.end());
	
	/*for(auto v:vec)	cout << v << " ";
	cout << endl;
	for(auto vr:rvec)	cout << vr << " ";
	cout << endl;*/
	
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		if(a==1){
			b--;
			printf("%d\n",vec[b]);
		}else{
			printf("%d\n", N - (lower_bound(rvec.begin(),rvec.end(),b) - rvec.begin() ) );
		}
	}
	
}
/*
5 8
100
240
80
90
75
1 1
2 95
1 4
2 80
2 50
1 5
2 120
2 100
*/
