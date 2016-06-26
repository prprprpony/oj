#include <iostream>
#include <iomanip>
#include <vector>
#define MAXD 159
using namespace std;
typedef long long ll;

struct Int
{
    vector<ll> d;
    static const ll base = 1e9;
    static const int width = 9;

    Int() {d.push_back(0);}

    Int(int a) {
        d.clear();
        do {
            d.push_back(a % base);
            a /= base;
        } while (a);
    }

    Int operator = (int a) {
        return *this = Int(a);
    }

    Int operator += (const Int& a) {
        if (d.size() < a.d.size())
            d.resize(a.d.size(), 0);
        ll carry = 0;
        int i;
        for (i = 0; i < a.d.size(); i++) {
            d[i] += a.d[i] + carry;
            if (d[i] >= base) {
                carry = 1;
                d[i] -= base;
            } else {
                carry = 0;
            }
        }
        for ( ; carry && i < d.size(); i++) {
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

    Int operator - (const Int& b) { // precondition: this >= b
        Int a = *this;
        int i;
        for (i = 0; i < b.d.size(); i++) {
            if ((a.d[i] -= b.d[i]) < 0) {
                a.d[i+1]--;
                a.d[i] += base;
            }
        }
        for ( ; i + 1 < a.d.size() && a.d[i] < 0; i++) {
            a.d[i+1]--;
            a.d[i] += base;
        }
        while (!a.d.back() && a.d.size() > 1)
            a.d.pop_back();
        return a;
    }

    bool operator == (const Int& a) const {
        if (d.size() != a.d.size())
            return false;
        for (int i = d.size() - 1; i >= 0; i--)
            if (d[i] != a.d[i])
                return false;
        return true;
    }

    bool operator == (int a) const {
        return *this == Int(a);
    }

    Int operator * (const Int& b) {
        if (*this == 0 || b == 0)
            return Int();
        else if (*this == 1)
            return b;
        else if (b == 1)
            return *this;
        Int c;
        for (int i = 0; i < d.size(); i++) {
            ll carry = 0;
            for (int j = 0; j < b.d.size(); j++) {
                if (i + j == c.d.size())
                    c.d.push_back(0);
                if ((c.d[i+j] += d[i] * b.d[j] + carry) >= base) {
                    carry = c.d[i+j] / base;
                    c.d[i+j] %= base;
                } else {
                    carry = 0;
                }
            }
            if (carry)
                c.d.push_back(carry);
        }
        return c;
    }
};

ostream& operator << (ostream& out, const Int& a) {
    out << a.d.back();
    for (int i = a.d.size() - 2; i >= 0; i--)
        out << setw(Int::width) << setfill('0') << a.d[i];
    return out;
}

Int f[MAXD][MAXD]; // f[n][d] = number of ways to put n pairs of parenthesis such that depth <= d

int main()
{
    for (int d = 0; d <= 150; d++)
        f[0][d] = 1;
    for (int n = 1; n <= 150; n++)
        for (int d = 1; d <= 150; d++)
            for (int i = 0; i < n; i++)
                f[n][d] += f[i][d-1] * f[n-i-1][d];
    ios_base::sync_with_stdio(false);
    int n, d;
    while (cin >> n >> d)
        cout << f[n/2][d] - f[n/2][d-1] << '\n';
    return 0;
}
