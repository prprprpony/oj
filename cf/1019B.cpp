#include <bits/stdc++.h>
using namespace std;
/* nichijou */
template<class T,class U>
bool cmax(T & a, const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a, const U & b) {return b < a ? a = b, 1 : 0;}
/* data type */
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
/* STL container */
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define CLR(a) (a).clear()
#define BK(a) ((a).back())
#define FT(a) ((a).front())
#define DB(a) (a).pop_back()
#define DF(a) (a).pop_front()
#define PB push_back
#define EB emplace_back
/* I gave you my heart and then you turned around. */
void _BG(const char * s) {cerr<<s<<endl;}
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
    for (size_t c = 0; *s && (c || *s != ','); cerr << *s++)
        c += count(ALL("([{"),*s) - count(ALL(")]}"),*s);
    cerr << " = " << a;
    if (*s) {
        cerr << ", ";
        ++s;
    }
    _BG(s,b...);
}
#ifdef PR3PONY
#define BG(...) do { \
    cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
    _BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)
#else
#define BG(...)
#endif
/* Good Luck && Have Fun ! */
int n;
int f(int i)
{
    int x, y;
    cout << "? " << i << endl;
    cin >> x;
    cout << "? " << i + n / 2 << endl;
    cin >> y;
    return x - y;
}
void ans(int i)
{
    cout << "! " << i << endl;
    exit(0);
}
int main()
{
    cin >> n;
    int lv = f(1);
    if (lv == 0)
        ans(1);
    if (lv % 2)
        ans(-1);
    int l = 2, r = n / 2;
    while (l <= r) {
        int m = (l + r) / 2;
        int mv = f(m);
        if (mv == 0)
            ans(m);
        if ((mv < 0) == (lv < 0))
            l = m + 1;
        else
            r = m - 1;
    }
}
