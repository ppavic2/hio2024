#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1005;

int n;
int deg[maxn];
int col[maxn];
int adj[maxn][maxn];
int c[2][2] = {{3, 1}, {2, 3}};

int main() {
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> adj[i][j], deg[i]++;

	for(int i = 0;i < n;i++) {
		if(deg[i] == n - 1) {
			cout << "-1\n";
			return 0;
		}
	}

	for(int i = 0;i < n;i++) {
		int a = rng();
		if(a < 0) a += INT_MAX;
		col[i] = a % 2;
	}

	cout << 3 << "\n";
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(adj[i][j])
				adj[i][j] = c[col[i]][col[j]];
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}