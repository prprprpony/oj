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

const int N = 1e5 + 87;
struct node
{
    int v,sz;
    node * c[2];
} mem[N];
node * ptr = mem;
node * newnode(int v)
{
    ptr->v=v;
    ptr->sz=1;
    return ptr++;
}
int sz(node *t)
{
    return t ? t->sz : 0;
}
void pull(node * t)
{
    t->sz = 1 + sz(t->c[0]) + sz(t->c[1]);
}
void rot(node*&t,int d)
{
    node * k = t->c[d];
    t->c[d] = k->c[d^1];
    pull(t);
    k->c[d^1] = t;
    pull(t = k);
}
template<typename func,typename ... T>
void splay(node *& t, const func & f, T ... a)
{
    int d = f(t,a...);
    if (~d) {
        node *& p = t->c[d];
        int d1 = f(p,a...);
        if (~d1) {
            splay(p->c[d1],f,a...);
            if (d == d1)
                rot(t,d);
            else
                rot(p,d1);
        }
        rot(t,d);
    }
}
auto fsz = [] (node *& t, int & k) -> int
{
    int r = sz(t->c[0]) + 1;
    if (k == r)
        return -1;
    int d = k > r;
    if (d)
        k -= r;
    return d;
};
auto fv = [] (node *& t, int v) -> int
{
    if (t->v == v)
        return -1;
    int d = t->v < v;
    return t->c[d] ? d : -1;
};
auto fins = [] (node *& t, int v) -> int
{
    if (!t)
        t = newnode(v);
    if (t->v == v)
        return -1;
    return t->v < v;
};
int main()
{
    char cmd[16];
    int x;
    node * rt = NULL;
    while (RD(cmd) && *cmd != 'e') {
		RD(x);
        if (*cmd == 'i')
            splay(rt,fins,x);
        else if (*cmd == 'r'){
            if (!rt)
                continue;
            splay(rt,fv,x);
            if (rt->v == x) {
                node * l = rt->c[0];
                node * r = rt->c[1];
                if (l) {
                    splay(l,fsz,sz(l));
                    l->c[1] = r;
                    pull(l);
                    rt = l;
                } else {
                    rt = r;
                }
            }
        } else {
            if (x < 1 || x > sz(rt)) {
                PL("error");
                continue;
            }
            splay(rt,fsz,x);
            PL(rt->v);
        }
    }
}
