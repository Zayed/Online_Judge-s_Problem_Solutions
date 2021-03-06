// Codeforces 747B - Mammoth's Genome Decoding.cpp

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
#include <set>

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
#define PC cout << "Case "//NOTES:cout
#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
///************************************************************///
#define INF (1 << 31) - 1
#define MOD 1000000007
#define pii pair<int, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define PI 2 * acos(0.0);
#define EPS 1e-11;
///************************************************************///
// Numeric Functions
// Translator Functions
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
string S;
map<char, int> MAP;

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, x = 0, y = 0, mx = 0;
	///READ();
	///WRITE();
	cin >> len >> S;

	mx = len / 4;

	MAP['A'] = 0;
	MAP['C'] = 0;
	MAP['G'] = 0;
	MAP['T'] = 0;

	for(I = 0; I < len; I++)
	{
		if(S[I] == '?')
			x++;
		else
			MAP[S[I]]++;
	}

	//cout << x << ' '<< mx << NL;
	y = x;
	map<char, int>::iterator it = MAP.begin();
	while(it != MAP.end())
	{
		if(it -> second > mx)
		{
			cout << "===\n";
			return 0;
		}

		if(it -> second < mx)
		{
			if(x <= 0)
			{
				cout << "===\n";
				return 0;
			}
			x = x - (mx - it -> second);
		}
		it++;
	}

	if(x > 0)
	{
		cout << "===\n";
		return 0;
	}
	//cout << "x = " << x << NL;

	it = MAP.begin();
	while(it != MAP.end())
	{
		if(it -> second < mx)
		{
            for(I = 0; I < len; I++)
			{
				if(it -> second == mx)
					break;

				if(S[I] == '?')
				{
					S[I] = it -> first;
					it -> second++;
				}
			}
		}
		it++;
	}
	cout << S << NL;

	return 0;
}

/*
8
???AAA??
*/

