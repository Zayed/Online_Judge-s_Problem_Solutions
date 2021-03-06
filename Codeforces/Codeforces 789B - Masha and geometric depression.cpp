// Codeforces 789B - Masha and geometric depression.cpp

/// Template by Zayed ///

///************************************************************///
/// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
///************************************************************///
#define INF (1 << 31) - 1
#define MOD 1000000007
#define PB push_back
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
#define PI 2 * acos(0.0);
#define EPS 1e-11;
///************************************************************///
// Numeric Functions
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base; return res;
}
// Translator Functions
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

const int SIZE = 1e6;
map<LL, LL> MAP;


int main()
{
	BOOST
	///READ();
	///WRITE();
	int tcases, I, J, K, N, n, cnt = 0, len, good = 0;

	LL b1, q, L, m;

	cin >> b1 >> q >> L >> m;

	for(I = 0; I < m; I++)
	{
		cin >> n;
		MAP[n]++;
	}

	if(abs(b1) > L)
	{
		cout << 0 << NL;
		return 0;
	}

	if(b1 == 0)
	{
		if(MAP[0] != 0)
			cout << 0 << NL;
		else
			cout << "inf\n";

		return 0;
	}

	if(q == 0)
	{
		if(MAP[0] == 0)
			cout << "inf\n";
		else if(MAP[b1] != 0)
			cout << 0 << NL;
		else
			cout << 1 << NL;

		return 0;
	}

	if(q == 1)
	{
		if(MAP[b1] != 0)
			cout << 0 << NL;
		else
			cout << "inf\n";

		return 0;
	}

	if(q == -1)
	{
		if(MAP[b1] != 0 && MAP[-b1] != 0)
			cout << 0 << NL;
		else
			cout << "inf\n";

		return 0;
	}

	while(abs(b1) <= L)
	{
		if(MAP[b1] == 0)
			good++;

		b1 = b1 * q;
	}

	cout << good << NL;


	return 0;
}
