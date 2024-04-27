#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N=1010;
int gr[N][N],ou[N][N],n;
bool bio[N];
bitset<N> fin[N],cur[N];
vector<int> ch[N],rch[N],ord,curcc;

void dfs1(int i)
{
	bio[i]=1;
	for (auto x: ch[i]) if (!bio[x]) dfs1(x);
	ord.push_back(i);
}

void dfs2(int i)
{
	bio[i]=1;
	curcc.push_back(i);
	for (auto x: rch[i]) if (!bio[x]) dfs2(x);
}

void tr(int col)
{
	for (int i=0;i<n;++i)
	{
		ch[i].clear();
		rch[i].clear();
		cur[i]=bitset<N>();
		bio[i]=0;
	}
	ord.clear();
	for (int i=0;i<n;++i) for (int j=0;j<n;++j) if (ou[i][j]==col) ch[i].push_back(j),rch[j].push_back(i);
	for (int i=0;i<n;++i) if (!bio[i]) dfs1(i);
	for (int i=0;i<n;++i) bio[i]=0;
	reverse(ord.begin(),ord.end());
	for (auto x: ord) if (!bio[x])
	{
		curcc.clear();
		dfs2(x);
		bitset<N> nap;
		for (auto y: curcc)
		{
			nap[y]=1;
			for (auto z: ch[y]) nap|=cur[z];
		}
		for (auto y: curcc) cur[y]=nap;
	}
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    n=inf.readInt();
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) gr[i][j]=inf.readInt();
    int best=ans.readInt(),cont=ouf.readInt();
    if (cont==-1 && best!=-1)
    {
    	quitf(_wa,"jury has solution but contestant does not");
	}
	if (cont==-1) quitf(_ok,"impossible");
	if (best!=-1 && cont>best)
	{
		quitf(_wa,"jury has better solution than contestant");
	}
	for (int i=0;i<n;++i) for (int j=0;j<n;++j)
	{
		ou[i][j]=ouf.readInt(0,cont);
		if (!ou[i][j] && gr[i][j])
		{
			quitf(_wa,"contestant didn't color an existing edge");
		}
		if (ou[i][j] && !gr[i][j])
		{
			quitf(_wa,"contestant colored an edge that doesn't exist");
		}
	}
	for (int i=1;i<=cont;++i)
	{
		tr(i);
		for (int j=0;j<n;++j) fin[j]|=cur[j];
	}
	for (int i=0;i<n;++i)
	{
		bool pos=1;
		for (int j=0;j<n;++j) if (!fin[i][j]) pos=0;
		if (pos)
		{
			quitf(_wa,"%d is special",i+1);
		}
	}
	if (cont<best)
	{
		quitf(_fail,"contestant has better answer");
	}
	if (best==-1 && cont!=-1)
	{
		quitf(_fail,"contestant has answer but jury does not");
	}
	quitf(_ok,"correct");
}
