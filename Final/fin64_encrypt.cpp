#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,K;
	deque<int> dq;
	cin >> N >> K;
	for(int i=0,x;i<N;i++){
		cin >> x;
		dq.push_back(x);
	}
	for(int i=1;i<=20-N;i++){
		dq.push_back(i);
	}
	for(int i=1;i<=K;i++){
		int save = dq.back();
		dq.pop_back();
		dq.push_front(save);
	}
	for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
        	printf("%d ",dq[i+j*5]);
		}
    }
}
