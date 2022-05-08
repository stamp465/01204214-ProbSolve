#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,x;
    cin >> a;
    int N=a.size(),j=0,countt=0;
    string ch,check;
    cin >> ch;
    for(int i=0;i<ch.size();i++){
        if(ch[i]==a[j])
        {
            check.push_back(ch[i]);
            j++;
            if(j>=N)	j=0;
        }
    }
    cout << check.size() / N;
}
