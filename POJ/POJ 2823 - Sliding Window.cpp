// POJ 2823 - Sliding Window.cpp

/// Template by Zayed ///

///#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

//#include <tuple>
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

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

using namespace std;
int caseno = 1;

#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
//#define BUG() printf("\n!!!!!!WHERE IS YOUR FOCUS!!!!!!\n") //NOTES:printf

#define BUG cout << "\n!!!!!!WHERE IS YOUR FOCUS!!!!!!\n" //NOTES:cout
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout

#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)

#define INTMAX (1LL << 31) - 1
#define LLMAX (1LL << 63) - 1
#define MOD 1000000007		    // (10^9 + 7)
#define PRIME 999998727899999   // (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
//#define tiii tuple<int, int, int>
#define PI 2 * acos(0.0)
#define EPS 1e-11


template< class T > bool Inside(T a, T b, T c) { return a <= b && b <= c; }
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL res = base; if (power == 0) return 1;
	for (int I = 0; I < power - 1; I++) res *= base; return res;
}

//Translator Functions
bool IsUpperCase(char c) { return c >= 'A' && c <= 'Z'; }//NOTES: IsUpperCase(
bool IsLowerCase(char c) { return c >= 'a' && c <= 'z'; }//NOTES: IsLowerCase(
bool IsLetter(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: IsLetter(
bool IsVowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }//NOTES: IsVowel(
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(

//int dx[] = {0, 0, -1, +1}, dy[] = {-1, +1, 0, 0}; //4 Direction Array
//int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1}; //8 Direction Array
//int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1}; //Knight Moves



const int SIZE = 1e6 + 10;
int ar[SIZE];
deque<int> DQ;




void FindMax(int n, int k)
{
    while(!DQ.empty())
        DQ.pop_front();

    int I;
    for(I = 0; I < k; I++)
    {
        while(!DQ.empty() && ar[DQ.back()] <= ar[I])
            DQ.pop_back();

        DQ.PB(I);
    }

    PF("%d", ar[DQ.front()]);

    for(I = k; I < n; I++)
    {
        while(!DQ.empty() && I - DQ.front() >= k)
            DQ.pop_front();

        while(!DQ.empty() && ar[DQ.back()] <= ar[I])
            DQ.pop_back();

        DQ.PB(I);

        PF(" %d", ar[DQ.front()]);

    }

    PF("\n");

}



void FindMin(int n, int k)
{
    while(!DQ.empty())
        DQ.pop_front();

    int I;
    for(I = 0; I < k; I++)
    {
        while(!DQ.empty() && ar[DQ.back()] >= ar[I])
            DQ.pop_back();

        DQ.PB(I);
    }

    PF("%d", ar[DQ.front()]);

    for(I = k; I < n; I++)
    {
        while(!DQ.empty() && I - DQ.front() >= k)
            DQ.pop_front();

        while(!DQ.empty() && ar[DQ.back()] >= ar[I])
            DQ.pop_back();

        DQ.PB(I);

        PF(" %d", ar[DQ.front()]);

    }

    PF("\n");

}



int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len;

    while(SF("%d%d", &n, &k) != EOF)
    {
        for(I = 0; I < n; I++)
            SF("%d", &ar[I]);

        FindMin(n, k);
        FindMax(n, k);

    }


	return 0;
}
