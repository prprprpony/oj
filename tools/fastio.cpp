#include <bits/stdc++.h>
using namespace std;
/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
template<typename T>
bool RD(T & a) 
{
	int c;
	while (!((c = getchar()) == '-' || isdigit(c) || c == EOF));
	if (c == EOF)
		return 0;
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
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)
#define DRIII(a,b,c) DRI(a); DRII(b,c)
#define DRIIII(a,b,c,d) DRI(a); DRIII(b,c,d)

/* For it's time for you to fulfill your output. */
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
template<typename T>
void PT(const T a)
{
	static const int maxd = 25;
	static char d[maxd];
	int i = maxd - 1;
	T t = a;
	if (t < 0) {
		do {
			d[--i] = -(t % 10) | 48;
		} while (t /= 10);
		d[--i] = '-';
	} else {
		do {
			d[--i] = (t % 10) | 48;
		} while (t /= 10);
	}
	PT(d + i);
}
void PT(const double a) {printf("%.16f", a);}
void PT(const char a) {putchar(a);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}
