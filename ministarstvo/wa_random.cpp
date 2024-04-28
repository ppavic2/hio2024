#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int x, int y) {
	int r = rng();
	if(r < 0) r += INT_MAX;
	return x + r % (y - x + 1);
}

const int maxn = 1005;

int n;
int deg[maxn];
int adj[maxn][maxn];

int main() {
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> adj[i][j], deg[i] += adj[i][j];

	int x = 0;
	for(int i = 1;i < n;i++)
		if(deg[i] > deg[x]) x = i;

	if(deg[x] == n - 1) {
		cout << "-1\n";
		return 0;
	}

	cout << "3\n";
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(adj[i][j]) 
				adj[i][j] = rand(1, 3);
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}