

#include<bits/stdc++.h>
using namespace std;

int N,dp[10050] = {0}; 
vector<int> save[10000];
struct Sct {
    int st, en, w;
}xxx;
int xx[10000]; 
int main()
{
    cin >> N;
    for(int i=0;i<N;i++){
    	cin >> xx[i];//.st >> xx[i].en >> xx[i].w;
	}
    
    
    //sort(xx,xx+N,[](Sct &x, Sct &y) {return x.en < y.en;});
 
    //dp[0] = xx[0].w;
    save[0].push_back(xx[0]);
 
    for (int i=1;i<N;i++){
    	//printf("%d %d %d ... %d\n",xx[i].st,xx[i].en,xx[i].w,dp[i]);
    	int last = 10000,nowsize=0;
        for(int j=i-1;j>=0;j--){
        	if( xx[j] < xx[i] && save[j].size() > nowsize ){
        		nowsize = save[j].size();
        		last = j;
        		//break;
			}
		}
 		//cout << dp[last] << "\n";
        //if (save[i-1].size() < save[last].size() + 1){
            //dp[i] = xx[i].w + dp[last];
            if (last != 10000) {
                save[i] = save[last];
            }
            save[i].push_back(xx[i]);
		/*}
        else {
            save[i] = save[i-1];
            //dp[i] = dp[i-1];
        }*/
        //cout << dp[i] << "\n";
    }
    int will = N-1,savei=0;
 	for(int i=0;i<N;i++){
 		if(save[i].size()>save[will].size() ) {
 			will = i ;
		}
	 }
    cout << save[will].size() << "\n";
    for(auto a:save[will]){
    	cout << a << " ";
	}
}

/*
5
1
2
2
3
4


5
1
-1
2
-2
3

5
5
4
3
2
1




*/
