// HackerRank - Contacts.cpp

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
string S, S1, S2;


struct node
{
	map<int, int> MAP;
	node *next[26 + 10];

	node()
	{
		MAP.clear();
		int I;
		for(I = 0; I < 26; I++)
			next[I] = NULL;
	}

};

node *root;

void Insert(string S2, int len)
{
	node *curr = root;

	int I;
	for(I = 0; I < len; I++)
	{
		int id = S2[I] - 'a';

		if(curr -> next[id] == NULL)
			curr -> next[id] = new node();

		curr -> MAP[id]++;
		curr = curr -> next[id];
	}

}

int Search(string S2, int len)
{
	node *curr = root;

	int I;
	for(I = 0; I < len; I++)
	{
		int id = S2[I] - 'a';

		if(curr -> next[id] == NULL)
			return 0;

		if(I == len - 1)
			return curr -> MAP[id];

		curr = curr -> next[id];
	}

	return 0;
}

void Del(node *curr)
{
	int I;
	for(I = 0; I < 26; I++)
	{
		if(curr -> next[I] != NULL)
			Del(curr -> next[I]);
	}

	delete(curr);
}

int main()
{
	BOOST
	///READ();
	///WRITE();
	int tcases, I, J, K, N, n, m, cnt = 0, len;

	root = new node();

	cin >> n;
	cin.ignore();

	for(I = 0; I < n; I++)
	{
		getline(cin, S);
		len = S.length();

		S1 = "", S2 = "";
		for(J = 0; J < len; J++)
		{
			if(S[J] == ' ')
				break;
			else
				S1 += S[J];
		}

		for(K = J + 1; K < len; K++)
				S2 += S[K];

		//cout << "S1 = " << S1 << " S2 = " << S2 << NL;

		if(S1 == "add")
		{
			len = S2.length();
			Insert(S2, len);
		}
		else
		{
			len = S2.length();
			int ret = Search(S2, len);

			cout << ret << NL;
		}

	}

	Del(root);

	return 0;
}

