#include<bits/stdc++.h>
using namespace std;

string s;
list<char> l;

int main(){
	while(getline(cin, s)){
		int status = 1;
		list<char>::iterator it;
		for(auto i : s){
			if(i=='[')	{
				status = 0;
				it = l.begin();
			}
			else if(i==']')	{
				status = 1;
			}
			else{
				//cout << i << " " << status << '\n';
				if(status == 1){
					l.emplace_back(i);
				}
				if(status == 0){
					l.insert(it,i);  
					//it++;
				}
			}
		}
		for(auto a:l){
			cout << a ;
		}cout << '\n';
		s.clear();
		l.clear();
	}
	
}
