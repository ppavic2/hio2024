#include <cstdio>
#include <chrono>
#include <iostream>
#include <random>
#include <cstring>

using namespace std;

int n, m;

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
    for(int i = 0;i < k;i++)
        ret = 10 * ret + s[i] - '0';
   	return ret;
}

const int N = 2050;

char ans[N][N];

int main(int argc, char** argv){
    int tip = to_int(argv[1]);
    int dens = to_int(argv[2]);
	rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
	
	int rub = (tip == 3 || tip == 5);
	
	int delta[7] = {-1, 100, 5, 10, 10, 100, 100};
	int maxn[7] = {-1, 2000, 10, 50, 50, 2000, 2000};
	
	int n = rint(maxn[tip] - delta[tip], maxn[tip]);
	int m = rint(maxn[tip] - delta[tip], maxn[tip]);
	
	int pos_red = rint(1, n - 1);
	memset(ans, '.', sizeof(ans));
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(rub && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) continue;
			if((i == 0 && j == 0) || (i == n - 1 && j == m - 1)) continue;
			if(tip == 1 && i != pos_red) continue;
			ans[i][j] = chp(dens);
		}
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