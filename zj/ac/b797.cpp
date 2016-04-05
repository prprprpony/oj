#include <bits/stdc++.h>
#define MAXN 40000
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

struct Int {
    vll d;
    static const ll base = 1e9;
    static const int width = 9;

    Int() {}
    Int operator = (ll v) {
        d.clear();
        do {
            d.push_back(v % base);
            v /= base;
        } while (v);
        return *this;
    }
    Int operator = (const string& s) {
        d.clear();
        for (int b = s.size() - 1; b >= 0; b -= width) {
            ll v = 0;
            for (int i = max(0, b - width + 1); i <= b; i++) {
                v = 10 * v + s[i] - '0';
            }
            d.push_back(v);
        }
        return *this;
    }
    Int operator += (const Int& a) {
        ll carry = 0;
        int i;
        for (i = 0; i < a.d.size(); i++) {
            if (i == d.size())
                d.push_back(0);
            d[i] += a.d[i] + carry;
            if (d[i] >= base) {
                d[i] -= base;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        for (; carry && i < d.size(); i++) {
            if (++d[i] >= base) {
                d[i] -= base;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry)
            d.push_back(1);
        return *this;
    }
};

ostream& operator << (ostream& out, const Int& a) {
    out << a.d.back();
    for (int i = a.d.size() - 2; i >= 0; i--)
        out << setw(Int::width) << setfill('0') << a.d[i];
    return out;
}

Int dp[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i <= MAXN; i++)
        dp[i] = 1;
    for (int i = 2; i * i <= MAXN; i++)
        for (int j = i * i; j <= MAXN; j++)
            dp[j] += dp[j - i * i];
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
/*
    cout << "#include <stdio.h>\n";
    cout << "char* ans[]={";
    for (int i = 0; i <= MAXN; i++)
        cout << '"' << dp[i] << '"' << (i != MAXN ? "," : "};");
    cout << "int main(void)";
    cout << "{";
    cout << "int t, n;";
    cout << "scanf(\"%d\", &t);";
    cout << "while (t--) {";
    cout << "scanf(\"%d\", &n);";
    cout << "puts(ans[n]);";
    cout << "}";
    cout << "return 0;";
    cout << "}";
*/
    return 0;
}
