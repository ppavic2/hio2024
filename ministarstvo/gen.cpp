#include<bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int rand(int x, int y) {
	return x + rand() % (y - x + 1);
}

int n;
int adj[maxn][maxn];

int main(int argc, char** argv) {
	int type = atoi(argv[1]);

	if(type == 1) {
		printf("3\n0 1 0\n0 0 1\n1 0 0\n");
		return 0;
	} 
	if(type == 2) {
		printf("3\n0 1 1\n0 0 1\n0 0 0\n");
		return 0;
	}
	if(type == 3) {
		printf("4\n0 1 1 0\n0 0 0 1\n0 1 0 1\n1 0 0 0\n");
		return 0;
	}
	if(type == 4) {
		n = atoi(argv[2]);
		int seed = atoi(argv[3]);
		srand(seed);

		for(int i = 0;i < n;i++) 
			for(int j = 0;j < i;j++)
				adj[i][j] = rand(0, 1), adj[j][i] = !adj[i][j];
	}
	if(type == 5) {
		n = atoi(argv[2]);
		int seed = atoi(argv[3]);
		srand(seed);

		adj[0][1] = adj[1][2] = adj[2][0] = 1;
		for(int i = 0;i < 3;i++)
			for(int j = 3;j < n;j++)
				adj[i][j] = 1;

		for(int i = 3;i < n;i++)
			for(int j = 3;j < i;j++)
				adj[i][j] = rand(0, 1), adj[j][i] = !adj[i][j];
	}
	if(type == 6) {
		n = atoi(argv[2]);
		int seed = atoi(argv[3]);
		srand(seed);

		for(int i = 1;i < n;i++)
			adj[0][i] = 1;

		for(int i = 1;i < n;i++)
			for(int j = 1;j < i;j++)
				adj[i][j] = rand(0, 1), adj[j][i] = !adj[i][j];
	}

	if(type == 7) {
		int c = atoi(argv[2]);
		if(c == 1) {
			n = 5;
			for(int i = 0;i < n;i++)
				for(int j = 0;j < n / 2;j++) {
					int x = (i + j + 1) % n;
					adj[i][x] = 1;
				}
		}
		if(c == 2) {
			n = 5;
			for(int i = 0;i < n;i++)
				for(int j = 0;j < i;j++)
					adj[i][j] = 1;
		}
		if(c == 3) {
			n = 5;
			adj[0][1] = adj[1][2] = adj[2][0] = 1;
			for(int i = 0;i < 3;i++)
				for(int j = 3;j < n;j++)
					adj[i][j] = 1;
			adj[3][4] = 1;
		}
	}
	if(type == 8) {
		n = 999;
		int c = atoi(argv[2]) - 1;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n / 2;j++) {
				int x = (i + j + 1) % n;
				adj[i][x] = c, adj[x][i] = !c;
			}
	}

	printf("%d\n", n);
	for(int i = 0;i < n;i++, printf("\n"))
		for(int j = 0;j < n;j++)
			printf("%d ", adj[i][j]);
	return 0;
}