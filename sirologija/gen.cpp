#include <cstdio>
#include <chrono>
#include <iostream>
#include <random>
#include <cassert>
#include <cstring>

using namespace std;

mt19937 rng;

int rint(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

char chp(int p) {
	return rint(0, 99) < p ? '#' : '.';
}

/**

SUBTASKOVI:

	1. - ISTI RED 			- 15 bodova
	2. - n <= 10  			- 18 bodova
	3. - n <= 50, nema ruba - 16 bodova
	4. - n <= 50			- 18 bodova
	5. - n <= 2000			- 16 bodova
	6. - n <= 2000			- 17 bodova

**/

int to_int(char *s){
    int ret = 0, k = strlen(s);
    for(int i = 0;i < k;i++) {
        ret = 10 * ret + s[i] - '0';
    }
   	return ret;
}

const int N = 2050;

char ans[N][N];
int n, m;

void random_path(int x, int y) {
	ans[x][y] = '.';
	if(x == n - 1 && y == m - 1) return;
	if(x == n - 1) { random_path(x, y + 1); return; }
	if(y == m - 1) { random_path(x + 1, y); return; }
	int z = rint(0, 1);
	random_path(x + z, y + 1 - z);
}

int main(int argc, char** argv){
    int tip = to_int(argv[1]);
    int dens = to_int(argv[2]);
    int gen_type = to_int(argv[3]);
	rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
	
	int rub = (tip == 3 || tip == 5);
	
	int delta[7] = {-1, 100, 5, 10, 10, 100, 100};
	int maxn[7] = {-1, 2000, 10, 50, 50, 2000, 2000};
	int prazn[7] = {-1, 0, 0, 6, 6, 50, 50};
	
	n = rint(maxn[tip] - delta[tip], maxn[tip]);
	m = rint(maxn[tip] - delta[tip], maxn[tip]);
	int praz = prazn[tip];
	

	
	if(gen_type == 0) {
		int pos_red = rint(1, n - 1);
		memset(ans, '.', sizeof(ans));
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				if(rub && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) continue;
				if((i == 0 && j == 0) || (i == n - 1 && j == m - 1)) continue;
				if(n > 30 && ((i < praz && j < praz) || (n - i < praz + 1 && n - j < praz + 1))) continue;
				if(tip == 1 && i != pos_red) continue;
				ans[i][j] = chp(dens);
			}
		}
	} else if(gen_type == 1) {
		assert(tip != 1);
		assert(dens > 0);
		memset(ans, '#', sizeof(ans));
		for(int i = 0;i < dens;i++) {
			random_path(0, 0);
		}
		for(int i = 0;i < (n / 3) * n;i++)
			ans[rint(0, n - 1)][rint(0, m - 1)] = '.';
	} else if(gen_type == 2) {
		int kad = rint(0, 1);
		memset(ans, '.', sizeof(ans));
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				if(rub && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) continue;
				if((i == 0 && j == 0) || (i == n - 1 && j == m - 1)) continue;
				if((((kad ^ i) | (kad ^ j))) & 1) continue;
				ans[i][j] = chp(dens);
			}
		}
	} else if(gen_type == 3) {
		int kad = rint(0, 1);
		memset(ans, '.', sizeof(ans));
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				if(rub && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) continue;
				if((i == 0 && j == 0) || (i == n - 1 && j == m - 1)) continue;
				int tdens = dens;
				if((((kad ^ i) | (kad ^ j))) & 1) tdens = 1;
				ans[i][j] = chp(tdens);
			}
		}
	} else if(gen_type == 4) {
		memset(ans, '.', sizeof(ans));	
	} else if(gen_type == 5) {
		int pos_red = rint(1, n - 1);
		if(tip == 1) {
			memset(ans, '.', sizeof(ans));
			for(int j = 0;j < m;j++) ans[pos_red][j] = '#';
		} else {
			memset(ans, '#', sizeof(ans));
			random_path(0, 0);
			for(int i = 0;i < n;i++) {
				for(int j = 0;m - j - 1 > j;j++)
					swap(ans[i][j], ans[i][m - j - 1]);
			}
			for(int i = 0;i < n;i++)
				for(int j = 0;j < m;j++)
					ans[i][j] = (ans[i][j] == '#') ? '.' : '#';
			ans[0][0] = '.'; ans[n - 1][m - 1] = '.';
		}
	} else {
		assert(false);
	}
	if(rub) {
		for(int i = 0;i < n;i++) ans[i][0] = '.', ans[i][m - 1] = '.';
		for(int i = 0;i < m;i++) ans[0][i] = '.', ans[n - 1][i] = '.';
	}
	printf("%d %d\n", n, m);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
