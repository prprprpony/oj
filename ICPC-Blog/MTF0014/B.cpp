#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
ll f(ll n) {return n*(n+1)*(2*n+1)/3*2 - 2*(n+1)*n + n;}
const int N = 1700;
int c[N][N];
map<pii,int> mp;
void add(int a,int b)
{
    if (a > b)
        swap(a,b);
    if (a)
        ++mp[{a,b}];
}
bool ok()
{
    bool f = 1;
    for (auto it = begin(mp); it != end(mp); ++it)
        f &= c[it->F.F][it->F.S] >= it->S;
    return f;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    ll V = 0;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        cin >> c[a][b];
        V += a * b * c[a][b];
    }
    int lo = 1, hi = 1;
    while (f(hi) <= V) hi <<= 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (f(mi) <= V)
            lo = mi + 1;
        else
            hi = mi - 1;
    }
    const int n = hi;
    for (int a = 0; a <= 2 * n - 1; ++a)
        for (int b = 0; b <= 2 * n - 1; ++b) {
            mp.clear();
            add(a,b);
            add(a,2*n-1-b);
            add(2*n-1-a,b);
            add(2*n-1-a,2*n-1-b);
            if (ok()) {
                cout << a << ' ' << b << endl;
                return 0;
            }
        }
}
