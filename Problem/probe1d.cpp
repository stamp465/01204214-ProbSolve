#include "probelib.h"
#include <bits/stdc++.h>
using namespace std;

int n;



main()
{
  	int n = probe_init();
	int left = 0;
	int right = n-1;
	while( left < right ){
		int mid = (right+left)/2;
		//printf("%d %d %d\n",left,mid,right);
		if( probe_check(left,mid) ){
			if(left==mid){
				probe_answer(left);
			}
			else{
				right = mid;
			}
		}
		else{
			if(right==mid+1){
				probe_answer(right);
			}
			else{
				left = mid+1;
			}
		}
	}
  	probe_answer(n-1);
  
}
