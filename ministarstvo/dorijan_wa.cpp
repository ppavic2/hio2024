#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using vl=vector<ll>;
#define pb push_back
#define all(a) begin(a),end(a)

const int N=1010,MOD=1e9+7;
const char en='\n';
const ll LLINF=1ll<<60;

int n,oud[N],gr[N];
int h[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(324);
	cin>>n;
	int mak=0;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j) cin>>h[i][j],oud[i]+=h[i][j];
		if (oud[i]>oud[mak]) mak=i;
		gr[i]=rand()%3+1;
	}
	if (oud[mak]==n-1)
	{
		cout<<-1<<en;
		exit(0);
	}
	cout<<3<<en;
	for (int i=0;i<n;++i,cout<<en) for (int j=0;j<n;++j)
	{
		if (h[i][j]==0) cout<<"0 ";
		else
		{
			cout<<gr[j]<<' ';
		}
	}
}
