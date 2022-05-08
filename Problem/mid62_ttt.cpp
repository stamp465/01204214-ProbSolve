#include<bits/stdc++.h>
using namespace std;

int N,M;
int color[3500];
pair<int,int> p[3500];
vector<int> vec[3500];

int isBi(int notuse)
{
	for(int j=0;j<1500;j++){
		color[j] = 0;
	}
    color[1] = 1; 
    queue <int> q;
    q.push(1);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int ii=0;ii<vec[temp].size();ii++){
        	int go = vec[temp][ii];
        	
        	if( temp == p[notuse].first && go == p[notuse].second) continue;
			if( temp == p[notuse].second && go == p[notuse].first) continue;
			
			if (color[go] == color[temp]) 
                return 0; 
            
			if (color[go] == 0) {
                color[go] = 3 - color[temp];
                q.push(go);
            }
                                             
        }
    }
    return 1;
}

int main(){
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		cin >> p[i].first >> p[i].second;
		vec[ p[i].first ].emplace_back( p[i].second );
		vec[ p[i].second ].emplace_back( p[i].first );
		
		//cout << i << "\n";
		//cout << p[i].first << " " << p[i].second << "\n";
	}
	for(int i=1;i<=M;i++){
		if(isBi(i)){
			cout << p[i].first << " " << p[i].second << "\n";
			break;
		}
		
		
	}
	
}
