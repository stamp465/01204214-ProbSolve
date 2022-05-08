#include "traffic.h"
#include <bits/stdc++.h>

using namespace std;

int n,k;
int arr[100000];
vector< pair<int,int> > ans;

int search(int colx,int rowx,int coly,int rowy){
	if(coly-colx==1 or rowy-rowx==1){ 
		ans.push_back({colx,rowx}); 
		ans.push_back({coly,rowy}); 
		return 0; 
	}
    int midcol = (colx+coly)/2;
	int midrow = (rowx+rowy)/2;
    if(	traffic_query(colx,rowx,midcol,midrow) != abs(colx-midcol)+abs(rowx-midrow) ) 
		search(colx,rowx,midcol,midrow);
    if(	traffic_query(midcol,midrow,coly,rowy) != abs(coly-midcol)+abs(rowy-midrow) ) 
		search(midcol,midrow,coly,rowy);
}

main()
{
	traffic_init(&n,&k);
	//printf("col\n");
	for(int i=1;i<=n;i++){
		if( traffic_query(i,1,i,n) != abs(i-i)+abs(1-n) ){
			search(i,1,i,n);
			//printf("%d\n",i);
		}
		if(ans.size()==2*k) break;
		//printf("i = %d %d \n",i,traffic_query(i,1,i,n));
	}
	//printf("row\n");
	for(int i=1;i<=n;i++){
		if( traffic_query(1,i,n,i) != abs(1-n)+abs(i-i) ){
			search(1,i,n,i);
			//printf("%d\n",i);
		}
		if(ans.size()==2*k) break;
		//printf("i = %d %d \n",i,traffic_query(1,i,n,i));
	}
	int j=0;
	for(int i=0;i<ans.size();i++){
		arr[j] = ans[i].first;
		j++;
		arr[j] = ans[i].second;
		j++;
	}
	traffic_report(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
}
