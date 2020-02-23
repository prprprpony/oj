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
const int N = 5e5 + 87;
void gao(int n, int v[], ll su[])
{
    vector<pll> st = {{-1, 0}};
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        ll c = 1;
        while (st.back().F >= v[i]) {
            auto p = st.back();
            st.pop_back();
            c += p.S;
            s -= p.F * p.S;
        }
        s += c * v[i];
        st.EB(v[i], c);
        su[i] += s;
    }
}
int n, v[N], a[N];
ll su[N];
void mk(int j)
{
    a[j] = v[j];
    for (int i = j - 1; i >= 0; --i) a[i] = min(a[i + 1], v[i]);
    for (int i = j + 1; i < n; ++i) a[i] = min(a[i - 1], v[i]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    gao(n, v, su);
    reverse(v, v + n);
    reverse(su, su + n);
    gao(n, v, su);
    reverse(v, v + n);
    reverse(su, su + n);
    pll ans(0, -1);
    for (int i = 0; i < n; ++i)
        ans = max(ans, pll(su[i] - v[i], i));
    mk(ans.S);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " \n"[i == n - 1];
}
