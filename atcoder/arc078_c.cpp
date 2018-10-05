#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
bool ask(T x)
{
    static int tot = 0;
    ++tot;
    cerr << "ASK " << tot << endl;
    cout << "? " << x << endl;
    char c;
    cin >> c;
    return c == 'Y';
}
void ans(ll x)
{
    cout << "! " << x << endl;
    exit(0);
}
int main()
{
    ll p10[11];
    p10[0] = 1;
    for (int i = 1; i < 11; ++i)
        p10[i] = 10 * p10[i - 1];

    int lo = 0, hi = 10;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (ask(p10[mi]))
            lo = mi + 1;
        else
            hi = mi - 1;
    }
    if (lo == 11) {
        if (ask(2))
            ans(1);
        for (int i = 1; i < 11; ++i)
            if (ask(p10[i] + 1))
                ans(p10[i]);
    }
        
    int len = hi + 1;
    ll a = 0;
    for (int i = 0; i < len - 1; ++i) {
        lo = 0, hi = 9;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (ask(10 * a + mi))
                lo = mi + 1;
            else
                hi = mi - 1;
        }
        a = 10 * a + hi;
    }
    lo = 0, hi = 9;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (ask(100 * a + 10 * mi))
            hi = mi - 1;
        else
            lo = mi + 1;
    }
    ans(a * 10 + lo);
}
