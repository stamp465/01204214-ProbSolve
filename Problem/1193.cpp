#include<bits/stdc++.h>
using namespace std;

int ans=0,n,r;
pair<double,double> p[1500];
int can;

int main(){
	int k=1;
	while(1){
		ans = 0;
		can = 1;
		cin >> n >> r;
		if(n==0&&r==0){
			break;
		}
		for(int i=0;i<n;i++){
			double x,y;
			cin >> x >> y;
			if(y>r) can=0;
			p[i].first  = x-sqrt(r*r-y*y);
			p[i].second = x+sqrt(r*r-y*y);
			//cout << p[i].first << "..." << p[i].second << "\n";
		}
		
		if(can==0){
			printf("Case %d: %d\n",k,-1);
			k++;
			continue;
		}
		
		sort(p,p+n);
		
		double r;
	
	    int i = 0;
	    while(i < n) {
	    	
			ans++;
	        r = p[i].second;
			
	        while(i < n && p[i].first <= r) {
	        	if( r > p[i].second )	r = p[i].second;
	            i++;
	        }
	        
	    }
		
		printf("Case %d: %d\n",k,ans);
		k++;
	}
}
