// Codeforces 586A - Alena's Schedule.cpp
#include<iostream>
#include<cstdio>

#include<cstring>
#include<string>
#include<sstream>

#include<cmath>
#include<cstdlib>
#include<cctype>
#include<ctime>

#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

#define  LL long long
#define MAX 100005
#define MOD 1000000007

#define NL '\n'

using namespace std;

// BEGINTEMPLATE_BY_ZAYED
typedef unsigned long long llu;
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int sz = 110;
template<class T> inline void checkmin(T &a, T b){ if (b<a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T &a, T b){ if (b>a) a = b; }//NOTES:checkmax(
template<class T> inline T sqr(T x){ return x*x; }//NOTES:square
int _max(int a, int b){ return (a > b) ? a : b; }
int _min(int a, int b){ return (a < b) ? a : b; }
inline int _pow(int base, int power){
	int I, result = base;
	for (I = 0; I < power - 1; I++) {
		result = result * base;
	}
	return result;
}
//Translator
bool isUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool isLowerCase(char c){ return c >= 'a' && c <= 'z'; }//NOTES: isLowerCase(
bool isLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool isDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char toLowerCase(char c){ return (isUpperCase(c)) ? (c + 32) : c; }//NOTES: toLowerCase(
char toUpperCase(char c){ return (isLowerCase(c)) ? (c - 32) : c; }//NOTES: toUpperCase(
int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
// ENDTEMPLATE_BY_ZAYED



int main()
{
	int a[sz];
	int n, cnt = 0;
	scanf("%d", &n);
	int I, K;
	for (I = 0; I < n; I++)
		scanf("%d", &a[I]);

	if (n == 0){
		printf("0\n");
		return 0;
	}
	I = 0;
	while (a[I] != 1 && I < n){
		I++;
	}

	K = I;
	while(K < n){
		if (a[K] == 1)
			cnt++;

		else if (a[K] == 0 && a[K + 1] == 1 && a[K  - 1] != 0)
			cnt++;

		K++;
	}
	printf("%d\n", cnt);
	return 0;
}