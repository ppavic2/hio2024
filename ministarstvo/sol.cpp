#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()

using namespace std;

const int maxn = 1005;

int n;
int deg[maxn];
int col[maxn];
int adj[maxn][maxn];
int c[2][2] = {{3, 1}, {2, 3}};

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%d", &adj[i][j]), deg[i] += adj[i][j];

	int x = 0;
	for(int i = 0;i < n;i++)
		if(deg[i] > deg[x]) x = i;
	if(deg[x] == n - 1) {
		printf("-1\n");
		return 0;
	}

	for(int i = 0;i < n;i++)
		if(adj[x][i]) col[i] = 1;

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if(adj[i][j])
				adj[i][j] = c[col[i]][col[j]];

	printf("3\n");
	for(int i = 0;i < n;i++, printf("\n"))
		for(int j = 0;j < n;j++) printf("%d ", adj[i][j]);
	return 0;
}