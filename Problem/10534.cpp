#include <bits/stdc++.h>
using namespace std;

int arr[10500];
int save_sizeF[10500],save_sizeR[10500];
vector<int> st,en;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        
        st.clear();
        en.clear();
        
        for(int i=1;i<=n;i++){
            cin >> arr[i];
            
            int it = lower_bound(st.begin(),st.end(),arr[i]) - st.begin();
            if(it == st.size())	st.push_back(arr[i]);
            else				st[it]=arr[i];
            
            save_sizeF[i]=it+1;
            
        }
        for(int i=n;i>=1;i--){
        	
            int it = lower_bound(en.begin(),en.end(),arr[i]) - en.begin();
            if(it == en.size())	en.push_back(arr[i]);
            else				en[it]=arr[i];
            
            save_sizeR[i]=it+1;
            
        }
        
        /*for(int i=1;i<=n;i++){
        	printf("%d ",save_sizeF[i]);
		}printf("\n");
		for(int i=1;i<=n;i++){
        	printf("%d ",save_sizeR[i]);
		}printf("\n");*/
		
		
		
        int maxx=1;
        for(int i=1;i<=n;i++){
            maxx = max(maxx,min(save_sizeF[i],save_sizeR[i])*2-1);
        }
        cout << maxx << "\n";
    }


}
