#include<bits/stdc++.h>
using namespace std;
vector<long long> vec;
long long a,b,n,nub=0;;
int main(){
	scanf("%lld %lld %lld",&n,&a,&b);
	for(int i=0;i<n;i++){
		//printf("%d ",i);
		long long p;
		scanf("%lld",&p);
		vec.emplace_back(p);
	}
	sort(vec.begin(),vec.end());
	
	/*for(auto a:vec)	cout << a << " ";
	cout << endl;*/
	
	for(auto it=vec.begin();it!=vec.end();it++){
		auto st = lower_bound(it+1, vec.end(), a-*it);
		auto en = upper_bound(it+1, vec.end(), b-*it);
		printf(".... %lld %d %d\n",*it,st-vec.begin(),en-vec.begin());
		//if(it==st) it++;
		if( (long long)(en - st) > 0 ) nub += (long long)(en - st);
	}
	printf("%lld\n",nub);
	
	/*long long nub2;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(vec[i]+vec[j] <= b && vec[i]+vec[j] >= a)	nub2++;
		}
	}cout << "nub2 = " << nub2 << endl;*/
}

/*
4 10 20
5
7
10
15

6 60 100
10
20
30
60
40
60

15 60 100
10
20
20
30
30
30
40
40
50
60
80
80
100
120
150
*/
