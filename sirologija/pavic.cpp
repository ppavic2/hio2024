#include <cstdio>
#include <iostream>

using namespace std;

const int N = 5050;

int n, m, sol, a[N][N];
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		cin >> s;
		for(int j = 0;j < m;j++)
			a[i][j] = s[j] == '#';
	}
	for(int i = 0;i < n;i++)
		for(int j = (!i);j < m;j++)\
			a[i][j] |= (i == 0 || a[i - 1][j]) && (j == 0 || a[i][j - 1]);
	for(int i = n - 1;i >= 0;i--)
		for(int j = m - 1 - (i == n - 1);j >= 0;j--)
			a[i][j] |= (i + 1 == n || a[i + 1][j]) && (j + 1 == m || a[i][j + 1]);
	if(a[0][0]) { cout << "0\n"; return 0; }
	for(int i = 1;i < n;i++)
		for(int j = 1;j < m;j++)
			if(a[i][j]) sol += (!a[i - 1][j]) && (!a[i][j - 1]) && (!a[i - 1][j - 1]);
	cout << sol + 1 << endl;
	return 0;
}
