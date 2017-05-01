#include<cstdio>
#include<cctype>
using namespace std;
template<typename T>
bool RD(T & a) 
{
	int c;
	while (!(isdigit(c = getchar()) || c == EOF));
	if (c == EOF)
		return 0;
	a = c&15;
	while (isdigit(c = getchar()))
		a = 10 * a + (c & 15);
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
		d[--i] = (t % 10) | 48;
	} while (t /= 10);
	PT(d + i);
}
/* The line will last forever! */
template<char sep = ' ',char end = '\n'>
void PL(void) {if (end) PT(end);}
template<char sep = ' ',char end = '\n',typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}
int main()
{
	int n,a;
	while (RD(n)) {
		for (a = 0; n /= 3; a += n);
		PL(a);
	}
}
