#include<bits/stdc++.h>
using namespace std;

int ans=0,n,r,nnn;
pair<int,int> pxy;
vector< pair<int,int> > save;
vector< pair<int,int> > p;
int can;

int main(){
	int k=1;	
	cin >> nnn ;
	while(nnn--){
		ans = 0;
		int endd = 0;
		cin >> endd;
		p.clear();
		while(1){
			int x,y;
			cin >> x >> y;
			if(x==0&&y==0)	break;
			pxy.first  = x;
			pxy.second = y;
			p.push_back(pxy);
			//cout << p[i].first << "..." << p[i].second << "\n";
		}
		
		save.clear();
		sort(p.begin(),p.end());
		
		int n=p.size();
		int r=0;
		int now = 0;
	    int i=0;
	    while(r < endd) {
	    	
	    	int cango = -1;
	    	int saver = r;
	    	while(i<n){
	    		if( p[i].first > saver ){
	    			break;
				}
				if( p[i].first <= saver && p[i].second >= saver && cango==-1 ){
					//cout << "..." << i << "\n";
					r = p[i].second;
					cango = i;
				}
				if( p[i].first <= saver && p[i].second >= saver && cango!=-1 ){
					//cout << "..." << i << "\n";
					if( p[i].second > p[cango].second ){
						r = p[i].second;
						cango = i;
					}
				}
				i++;
			}
	        if(cango==-1){
	        	break;
			}
			//cout << p[cango].first << "....." << p[cango].second << "\n";
			save.push_back( p[cango] );
	    }
	    if( r >= endd ){
			cout << save.size() << "\n";
			for(auto a:save){
				cout << a.first << " " << a.second << "\n";
			}
		}
		else{
			cout << "0\n";
		}
	}
}
