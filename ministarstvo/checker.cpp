// Checker to be used by HSIN evaluator.
//
// This should *not* be used for CMS!
//
// Usage: [checker] [input] [official_output] [contestant_output] [configuration_file (optional)]
//
// Output (stdout):
//     Score.
//     Textual description (optional).
//
// Score should be output as an integer (0 or 1), or a real (between 0.0 and
// 1.0) or a fraction (between `0/1` and `1/1`, you don't have to
// simplify/reduce the fraction).

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

// Use one of the following functions to output the points to the contestant.
// The first accepts a double and outputs it.
// The second accepts a fraction and outputs it.

void finish(double score, const string& message) {
  cout << score << endl;
  cout << message << endl;
  exit(0);
}

// Helper functions.
 
const int N=1010;
int gr[N][N],ou[N][N],n;
bool bio[N];
bitset<N> final[N],cur[N];
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
	vector<vector<int>> concc;
	for (auto x: ord) if (!bio[x])
	{
		curcc.clear();
		dfs2(x);
		concc.push_back(curcc);
	}
	reverse(concc.begin(),concc.end());
	for (auto curcc: concc)
	{
		bitset<N> nap;
		for (auto y: curcc)
		{
			nap[y]=1;
			for (auto z: ch[y]) nap|=cur[z];
		}
		for (auto y: curcc) cur[y]=nap;
	}
	//cout<<col<<endl;
	//for (int i=0;i<n;++i,cout<<endl) for (int j=0;j<n;++j) cout<<cur[i][j];
}

/**
 * The main checking function.
 * @param fin official input
 * @param foff official output
 * @param fout contestant's output
 */
void checker(ifstream &fin, ifstream &foff, ifstream &fout) {
  const string WRONG_OUTPUT_FORMAT = "Wrong output format.";
  const string TEST_DATA_ERROR = "Official input or output error.";
  const string WRONG_N = "Invalid number of operations.";
  const string WRONG_LABEL = "Invalid register label.";
  const string WRONG_VALUE = "Invalid value of a register.";
  const string WRONG_ANS = "Wrong answer.";
  const string CORRECT = "Correct.";

  // Read official input
  if (!(fin >> n)) finish(0, TEST_DATA_ERROR);

  for (int i=0;i<n;++i) for (int j=0;j<n;++j)
  {
  	if (!(fin >> gr[i][j])) finish(0, TEST_DATA_ERROR);
  }
  int best,cont;
  if (!(foff>>best)) finish(0, TEST_DATA_ERROR);
  if (!(fout>>cont)) finish(0, WRONG_ANS);
  if ((best==-1)!=(cont==-1)) finish(0, WRONG_ANS);
  if (best==-1) finish(1, CORRECT);
  for (int i=0;i<n;++i) for (int j=0;j<n;++j)
  {
  	if (!(fout>>ou[i][j])) finish(0.15, WRONG_ANS);
  	if (ou[i][j]<0 || ou[i][j]>cont) finish(0.15, WRONG_ANS);
  	if (!ou[i][j] && gr[i][j]) finish(0.15, WRONG_ANS);
  	if (ou[i][j] && !gr[i][j]) finish(0.15, WRONG_ANS);
  }
  for (int i=1;i<=min(cont,3);++i)
  {
  	tr(i);
	for (int j=0;j<n;++j) final[j]|=cur[j];
  }
  for (int i=0;i<n;++i)
  {
	bool pos=1;
	for (int j=0;j<n;++j) if (!final[i][j]) pos=0;
	if (pos) finish(0.15, WRONG_ANS);
  }
  if (cont<best) finish(0, TEST_DATA_ERROR);
  if (cont>best) finish(0.15, WRONG_ANS);
  finish(1, CORRECT);
}

int main(int argc, char *argv[]) {
  assert(argc >= 4);

  ifstream fin(argv[1]);
  ifstream foff(argv[2]);
  ifstream fout(argv[3]);

  // Optional, uncomment when using the configuration file for additional
  // information about the testcase.
  // ifstream fconf(argv[4]);

  assert(!fin.fail() && !fout.fail());
  checker(fin, foff, fout);

  // Checker must terminate via finish() before exiting!
  assert(false);

  return 0;
}
