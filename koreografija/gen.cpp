#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

//////////////////////////////////////////////////////////////////////////
mt19937 rng;

int rnd (int lo, int hi) {
    return uniform_int_distribution<int>(lo, hi)(rng);
}

void good_shuffle (vector <int> &v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        swap(v[i], v[rnd(0, i)]);
    }
}

void good_shuffle (vector <pi> &v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        swap(v[i], v[rnd(0, i)]);
    }
}
//////////////////////////////////////////////////////////////////////////

const int MAXN = 1005;

int n_limit = 1000, seed = 42069, subtask = 1;
int n;
int a[MAXN];

bool validate () {
    if (!(n == n_limit)) return 0;

    for (int i = 1; i <= n; i++) {
        if (!(1 <= a[i] && a[i] <= n)) return 0;
    }

    if (subtask == 1) {
        vector <int> v(n);
        for (int i = 1; i <= n; i++) {
            v[i - 1] = a[i];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != i + 1) return 0;
        }
    }

    return 1;
}

void ispis () {
    for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i < n) cout << " ";
    }
    cout << endl;
}

void napravi_primjer (string tip) {
    n = 1000;
    if (tip == "RASTE") {
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
    } else if (tip == "PADA") {
        for (int i = 1; i <= n; i++) {
            a[i] = n + 1 - i;
        }
    } else if (tip == "RANDOM") {
        vector <int> v(n);
        for (int i = 0; i < n; i++) v[i] = i + 1;
        good_shuffle(v);
        for (int i = 1; i <= n; i++) {
            a[i] = v[i - 1];
        }
    } else if (tip == "PADA_PA_RASTE") {
        for (int i = 1; i <= n / 2; i++) {
            a[i] = n / 2 + 1 - i;
        }
        for (int i = n / 2 + 1; i <= n; i++) {
            a[i] = i;
        }
    } else if (tip == "RASTE_PA_PADA") {
        for (int i = 1; i <= n / 2; i++) {
            a[i] = i;
        }
        for (int i = n / 2 + 1; i <= n; i++) {
            a[i] = n + n / 2 + 1 - i;
        }
    } else if (tip == "PADA_PA_PADA") {
        for (int i = 1; i <= n / 2; i++) {
            a[i] = n / 2 + 1 - i;
        }
        for (int i = n / 2 + 1; i <= n; i++) {
            a[i] = n + n / 2 + 1 - i;
        }
    } else if (tip == "RASTE_PA_RASTE") {
        for (int i = 1; i <= n / 2; i++) {
            a[i] = i;
        }
        for (int i = n / 2 + 1; i <= n; i++) {
            a[i] = i;
        }
    } else if (tip == "JEDAN_SWAP") {
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
        int i = rnd(1, n);
        int j = rnd(1, n);
        swap(a[i], a[j]);
    } else if (tip == "DVA_SWAPA") {
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
        int i = rnd(1, n - 4);
        swap(a[i], a[i + 1]);
        swap(a[i + 2], a[i + 3]);
    } else if (tip == "SUSJEDNI") {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) a[i] = i + 1; else a[i] = i - 1;
        }
    } else if (tip == "KORIJEN") {
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 20; j++) {
                a[i * 20 + j + 1] = (49 - i) * 20 + j + 1;
            }
        }
    }


    if (!validate()) {
        cerr << tip << " not valid!" << endl;
        exit(0);
    } else {
        cerr << tip << " is ok!" << endl;
    }
    ispis();
}

int main (int argc, char *argv[]) {
    assert(argc == 2 || argc == 3 || argc == 4);
    if (argc >= 3) subtask = atoi(argv[2]);
    if (argc >= 4) seed = atoi(argv[3]);
    rng.seed(seed);
    napravi_primjer(argv[1]);
    return 0;
}
