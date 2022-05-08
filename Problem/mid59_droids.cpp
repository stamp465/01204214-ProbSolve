#include<bits/stdc++.h>
using namespace std;

vector<int> vec;


int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0,x;i<N;i++){
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(),vec.end());
	int be=-1,sum=0;
	/*for(int i=0,x;i<N;i++){
		cout << vec[i] << " ";
	}cout << endl;*/
	for(int i=0,y;i<M;i++){
		cin >> y;
		int next,pos;
		pos = upper_bound(vec.begin(),vec.end(),y) - vec.begin();
		pos--;
		//cout << "pos = " << pos << " be = " << be << endl;
		//cout << "data pos = " << vec[pos] << endl;

			next = pos+1;
			if(next==be)	next++;
			if(pos==be)		pos--;
			if( next>=N ){
				//cout << "use = " << vec[pos] << endl;
				sum += y-vec[pos];
				be = pos;
			}
			else if( pos < 0 ){
				//cout << "use = " << vec[next] << endl;
				sum += vec[next]-y;
				be = next;
			}
			else if( y-vec[pos] <= vec[next]-y ){
				//cout << "use = " << vec[pos] << endl;
				sum += y-vec[pos];
				be = pos;
			}
			else if( y-vec[pos] > vec[next]-y ){
				//cout << "use = " << vec[next] << endl;
				sum += vec[next]-y;
				be = next;
			}
		
		
		
	}
	cout << sum << endl;
}

/*
5 6
40
10
55
20
80 
15
29
100
90
91
40

*/
