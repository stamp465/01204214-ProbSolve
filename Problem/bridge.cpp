#include<bits/stdc++.h>
using namespace std;

pair<int,int> arr[100000];
vector<int> vec;

int main()
{
	int n,maxx=0;
    cin >> n;
    for(int i=0,k;i<n;i++)
    {
        cin >> k;
        arr[k-1].first = i;
    }
	for(int i=0,k;i<n;i++)
    {
        cin >> k;
        arr[k-1].second = i;
    }
    
    /*printf("-----\n");
    for(int i=0;i<n;i++)
    {
		printf("i = %d -- %d %d \n",i,arr[i].first,arr[i].second);
    }*/
    
    sort(arr,arr+n);
    /*printf("-----\n");
    for(int i=0;i<n;i++)
    {
		printf("i = %d -- %d %d \n",i,arr[i].first,arr[i].second);
    }*/
    
    for(int i=0;i<n;i++)
    {
    	
		int check = arr[i].second;
        auto it = lower_bound(vec.begin(),vec.end(),check);
        if(it==vec.end()){
        	vec.push_back(check);
		}
		else{
			*it = check;
		}
		
		/*for( auto xx:vec){
    		cout << xx << " ";
		}cout << endl;*/
    }
   
    cout << vec.size();
}

/*
5
3
1
5
2
4
1
2
5
4
3

5
3
5
1
2
4
1
2
3
4
5
*/
