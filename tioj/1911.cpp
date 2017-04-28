#include<bits/stdc++.h>
using namespace std;
template<typename T>
bool RD(T & a) 
{
	int c;
	while (!((c = getchar()) == '-' || isdigit(c)));
	a = 0;
	if (c == '-') {
		while (isdigit(c = getchar()))
			a = 10 * a - (c & 15);
	} else {
		do {
			a = 10 * a + (c & 15);
		} while (isdigit(c = getchar()));
	}
	return 1;
}

/* For it's time for you to fulfill your output. */
void PT(const char a) {putchar(a);}
void PT(char * a) {fputs(a, stdout);}
template<typename T>
void PT(const T a)
{
	static const int maxd = 25;
	static char d[maxd];
	int i = maxd - 1;
	T t(a);
	do {
		d[--i] = (t - 10 * (int)((t * 56294995342132LL) >> 49)) | 48;
	} while (t = ((t * 56294995342132LL) >> 49));
	PT(d + i);
}

/* The line will last forever! */
template<char sep = ' ',char end = '\n'>
void PL(void) {if (end) PT(end);}
template<char sep = ' ',char end = '\n',typename T, typename ...  TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}

/* I DUCK HORSE */
const int N = 1e4;
int sz,f[N+1];
void add(int i,int v)
{
	sz += v;
	for ( ; i <= N; i += i & -i)
		f[i] += v;
}
int kth(int k)
{
	int v = 0, s = 0;
	for (int i = 1 << __lg(N); i; i >>= 1)
		if ((v | i) <= N && s + f[v | i] < k)
			s += f[v |= i];
	return v + 1;
}
int main()
{
	int a;
	while (RD(a) && a)
		if (a < 0) {
			if (!sz)
				continue;
			int v = kth(a == -2 ? sz : 1);
			PL<0,' '>(v);
			add(v,-1);
		} else {
			add(a,1);
		}
}
