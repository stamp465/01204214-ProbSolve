#include<bits/stdc++.h>
#define pair pair<int,int> 
using namespace std;

int number[100500];
priority_queue < pair , vector< pair >, greater< pair > > seller,buyer;

int main(){
	int N,sum=0;
	cin >> N;
	for(int i=1;i<=N;i++){
		int status,price;
		cin >> status >> price >> number[i];
		//if( !seller.empty() ) 	cout << seller.top().first << " seller " << seller.top().second << endl;
		//if( !buyer.empty() ) 	cout << buyer.top().first << " buyer " << buyer.top().second << endl;
		if(status==1){	//buyer
			while( !seller.empty() ){
				pair seller_choose = seller.top();
				//cout << "choose seller --- " << seller_choose.second << "---\n";
				if( seller_choose.first <= price){
					if( number[seller_choose.second] > number[i] ){
						//cout << number[seller_choose.second] << " > "<< number[i] << " in 1\n";
						sum += number[i]*price;
						number[seller_choose.second] -= number[i];
						number[i] -= number[i];
						break;
					}
					else{
						//cout << number[seller_choose.second] << " <= "<< number[i] << " in 2\n";
						sum += number[seller_choose.second]*price;
						
						number[i] -= number[seller_choose.second];
						number[seller_choose.second] -= number[seller_choose.second];
						seller.pop();
					}
				}
				else{
					break;
				}
				
			}
			if( number[i] > 0 ){	
				buyer.push({-price,i});
			}
		}
		else{	//seller
			while( !buyer.empty() ){
				pair buyer_choose = buyer.top();
				//cout << "choose buyer --- " << buyer_choose.second << "---\n";
				if( -buyer_choose.first >= price){
					if( number[buyer_choose.second] > number[i] ){
						//cout << number[buyer_choose.second] << " > "<< number[i] << " in 1\n";
						sum += number[i]*price;
						number[buyer_choose.second] -= number[i];
						number[i] -= number[i];
						break;
					}
					else{
						//cout << number[buyer_choose.second] << " <= "<< number[i] << " in 2\n";
						sum += number[buyer_choose.second]*price;
						
						number[i] -= number[buyer_choose.second];
						number[buyer_choose.second] -= number[buyer_choose.second];
						buyer.pop();
					}
				}
				else{
					break;
				}
				
			}
			if( number[i] > 0 ){	
				//cout << "number " << i << " = " << number[i] << "\n";
				seller.push({price,i});
			}	
		}
		
	}
	cout << sum << endl;
	
}
