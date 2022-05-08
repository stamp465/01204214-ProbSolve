#include<bits/stdc++.h>
using namespace std;

int n,m,nubgroup=1;
int visit[100500];
int degree[100500];
int group[100500];
vector<int> vec[100500];
vector< pair<int,int> > member[100500];

int fornub(int node){
	group[nubgroup] = node;
	visit[node] = 1;
	queue<int> q;
	q.push(node);
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		member[nubgroup].push_back({degree[now],now});
		for(int i=0;i<vec[now].size();i++){
			int willgo = vec[now][i];
            if(visit[willgo] == 1)		continue;
            visit[willgo] =1 ;
            q.push(willgo);
        }
	}
}

int from_center(int start,int endd){
	int nub = 0;
	queue< pair<int,int> > q;
	q.push({start,start});
	
	while(!q.empty()){
		int now = q.front().first;
		int be = q.front().second;
		q.pop();
		if( now==endd )	break;
		nub++;
		for(int i=0;i<vec[now].size();i++){
			int willgo = vec[now][i];
            if(willgo == be)		continue;
            q.push({willgo,now});
        }
	}
	
	return nub;
}

int member_of_loop(int start,int endd){
	int nub = 0;
	queue< pair<int,int> > q;
	q.push({start,start});
	int c=0;
	while(!q.empty()){
		int now = q.front().first;
		int be = q.front().second;
		q.pop();
		if( now==endd )	{
			c++;
			if(c==2)	break;
		}
		nub++;
		for(int i=0;i<vec[now].size();i++){
			int willgo = vec[now][i];
            if(willgo == be)		continue;
            q.push({willgo,now});
        }
	}
	
	return nub;
}

int main(){
	cin >> n >> m;
	for(int i=0,x,y;i<m;i++){
		cin >> x >> y;
		degree[x]++;	degree[y]++;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
	    if(visit[i]==0){
	    	fornub(i);
			nubgroup++;	
	    }
	}
	for(int i=1;i<nubgroup;i++){
	    sort(member[i].begin(),member[i].end());
	    /*cout << "Group " << i << "\n";
	    for(int xx=0;xx<member[i].size();xx++){
	        cout << member[i][xx].second << "---" << member[i][xx].first << "\n";
	    }*/
	}
	set<int> if_1_2,if_2_noC,if_2_C;
	set< pair<int,int> > if_3_C;
	set< tuple<int,int,int> > if_3_noC;
	for(int i=1;i<nubgroup;i++){
		int N_member = member[i].size();
	    if( N_member <= 2 ){
	    	if_1_2.insert(N_member);
		}
		else if( member[i][N_member-1].first == 2 ){
			if( member[i][0].first == 1 ){
				if_2_noC.insert(N_member);
			}
			else{
				if_2_C.insert(N_member);
			}
		}
		else{
	        if( member[i][0].first == 1 && member[i][1].first == 1 ){
	        	int center = member[i][N_member-1].second;
				int arr[10];
				arr[0] = from_center( member[i][0].second , center );
				arr[1] = from_center( member[i][1].second , center );
				arr[2] = from_center( member[i][2].second , center );
				sort(arr,arr+3);
				//printf("if3 ----- %d %d %d\n",arr[0],arr[1],arr[2]);
				if_3_noC.insert( make_tuple(arr[0],arr[1],arr[2]) );
	        }else{
	            int center = member[i][N_member-1].second;
	            int dis1 = from_center(member[i][0].second,center);
	            int dis2 = member_of_loop(center,center);
	            if_3_C.insert({dis1,dis2});
	        }
    	}
	}
	
	cout << if_1_2.size() + if_2_noC.size() + if_2_C.size() + if_3_noC.size() + if_3_C.size() ;
}


/*
20 10
4 7
18 16
14 16
7 13
10 2
3 8
11 20
13 17
12 9
8 10



100 50
84 87
78 16
94 36
87 93
50 22
63 28
91 60
64 27
41 27
73 37
12 69
68 30
83 31
63 24
68 36
30 3
23 59
94 57
12 43
22 20
85 38
99 25
16 71
92 81
57 74
97 82
6 26
85 28
37 6
14 58
25 96
83 46
35 65
44 51
88 9
77 79
4 52
55 100
33 61
77 69
40 13
95 40
96 71
35 79
98 3
18 93
2 81
66 90
45 20
32 18

1000 500

10000 5000

50000 20000


*/
