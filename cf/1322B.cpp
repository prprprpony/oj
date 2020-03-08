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
const int N = 4e5 + 87;
const int C = 2e7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int k = 0; (1 << k) <= C; ++k) {
        int cnt[2] = {};
        for (int x : a)
            ++cnt[x >> k & 1];
        cnt[1] += cnt[0];
        for (int i = n - 1; i >= 0; --i)
            b[ --cnt[a[i] >> k & 1] ] = a[i];
        swap(a, b);
        ll tot = 0;
        const int mask = (1 << (k + 1)) - 1;
        auto gao = [&](int vl, int vr) {
            int jl = 0, jr = 0;
            for (int i = n - 1; i >= 0; --i) {
                int x = a[i] & mask;
                while (jr < n && (a[jr] & mask) <= vr - x)
                    ++jr;
                while (jl < n && (a[jl] & mask) <= vl - x)
                    ++jl;
                tot += jr - jl;
                tot -= vl < 2 * x && 2 * x <= vr;
            }
        };
        gao((1 << k) - 1, (1 << (k + 1)) - 1);
        gao((3 << k) - 1, (1 << (k + 2)) - 1);
        tot /= 2;
        if (tot & 1)
            ans |= 1 << k;
    }
    cout << ans << endl;
}
