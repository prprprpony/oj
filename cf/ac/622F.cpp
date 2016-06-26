#include <cstdio>
#include <cassert>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;
const int MAXK = 1e6;

int p[MAXK + 1];

int gcd(int a, int b, int& x, int& y, int& g) {
    if (b) {
        gcd(b, a % b, y, x, g);
        y -= a / b * x;
    } else {
        x = a < 0 ? -1 : 1;
        y = 0;
        g = a * x;
    }
}

inline int normal(ll a) {return (a %= M) < 0 ? a + M : a;}

inline int inv(int a) {
    int x, y, g;
    gcd(a, M, x, y, g);
#ifdef PP
    printf("%d * %d + %d * %d = %d\n", a, x, M, y, g);
#endif
    assert(g == 1);
    return normal(x);
}

inline int mul(int a, int b) {return normal((ll)a * b);}
inline int add(int a, int b) {return normal(a + b);}
inline int div(int a, int b) {return mul(a, inv(b));}

int qpow(ll n, int k) {
    int p = 1;
    ll r = 1;
    for ( ; p <= k; n = mul(n, n), p <<= 1)
        if (p & k)
            r = mul(r, n);
    return r;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k + 1; i++)
        p[i] = add(p[i-1], qpow(i, k));
    // p(x) is a k + 1 degree polynomial
    int ans;
    if (n <= k + 1) {
        ans = p[n];
    } else { // Lagrange polynomial
        int l = 1;
        ans = 0;
        for (int i = 1; i <= k + 1; i++) // calculate l(0)
            l = mul(l, div(n - i, -i));
        for (int i = 1; i <= k + 1; i++) // skip p0 * l(0) since p0 = 0
            ans = add(ans, mul(p[i], l = div(mul(l, mul((i - 1) - (k + 1), n - (i - 1))), mul(i, n - i))));
    }
    printf("%d\n", ans);
        
    return 0;
}
