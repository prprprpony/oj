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
// Zpal() is copied from bcw_codebook
void Zpal(const char *s, int len, int *z) {
    // Only odd palindrome len is considered
    // z[i] means that the longest odd palindrom centered at
    // i is [i-z[i] .. i+z[i]]
    z[0] = 0;
    for (int b=0, i=1; i<len; i++) {
        if (z[b] + b >= i) z[i] = min(z[2*b-i], b+z[b]-i);
        else z[i] = 0;
        while (i+z[i]+1 < len and i-z[i]-1 >= 0 and 
               s[i+z[i]+1] == s[i-z[i]-1]) z[i] ++;
        if (z[i] + i > z[b] + b) b = i;
    }
}
void manacher(const string & s, int z[], int st[], int ed[], const char nil = '@')  
{
    // nil should be a character that is not in s
    // length of z should be at least 2n+1
    // for i in 1 .. 2n-1
    //     if i is odd:
    //          z[i] is the maximal length of odd palindrome centered at s[(i - 1) / 2]
    //          the palindrome is s[(i - z[i]) / 2 .. (i + z[i]) / 2 - 1]
    //     if i is even:
    //          z[i] is the maximal length of even palindrome centered at s[(i - 1) / 2] and s[(i - 1) / 2 + 1]
    // length of st and ed should be at least n
    // st[i]: the maximal length of palindrome starting at s[i]
    // ed[i]: the maximal length of palindrome ending at s[i]
    const int n = s.size();
    fill_n(st, n, 0);
    fill_n(ed, n, 0);
    const int m = 2 * n + 1;
    string t = string(m, nil);
    for (int i = 0; i < n; ++i)
        t[2 * i + 1] = s[i];
    Zpal(t.c_str(), m, z);
    for (int i = 1; i + 1 < m; ++i) {
        int l = (i - z[i] + 1 - 1) / 2;
        int r = (i + z[i] - 1 - 1) / 2;
        cmax(st[l], z[i]);
        cmax(ed[r], z[i]);
    }
    for (int i = 0; i + 1 < n; ++i)
        cmax(st[i + 1], st[i] - 2);
    for (int i = n - 1; i > 0; --i)
        cmax(ed[i - 1], ed[i] - 2);
}

const int N = 2e6 + 87;
int z[N], st[N], ed[N];
string solve()
{
    string s, ls, rs;
    cin >> s;
    if (equal(ALL(s), s.rbegin()))
        return s;
    int n = s.size(), k;
    for (k = 0; s[k] == s[n - 1 - k]; ++k)
        ls += s[k];
    rs = string(ls.rbegin(), ls.rend());
    s = s.substr(k, n - 2 * k);
    n = s.size();
    manacher(s, z, st, ed);
    ls += st[0] > ed[n - 1] ? s.substr(0, st[0]) : s.substr(n - ed[n - 1], ed[n - 1]);
    return ls + rs;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}
