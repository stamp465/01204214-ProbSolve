#include<bits/stdc++.h>
using namespace std;

int main() {
	int n=1;
	queue<int> que;

	while (1) {
		cin >> n;
		if(n==0)	break;
		for (int i = 1; i <= n; i++) {
			que.push(i);
		}

		cout << "Discarded cards:";
		while (1) {
			if( que.size() <= 1 )	break;
			cout << " " << que.front();
			que.pop();
			int tmp = que.front();
			que.pop();
			if (!que.empty())	cout << ",";
			que.push(tmp);
		}
		cout << "\n";
		cout << "Remaining card: " << que.front();
		cout << "\n";
		que.pop();
	}

	return 0;
}
