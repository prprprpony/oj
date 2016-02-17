#include <bits/stdc++.h>
#define MAXL 102 + 42
#define MAXV (int)(1e9)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

struct Int {
    static const ll base = 1e9;
    static const int len = 9;
    vll d;

    Int() {}

    Int(ll v) {
        do {
            d.push_back(v % base);
            v /= base;
        } while (v);
    }

    Int(const string& s) {
        for (int b = s.size() - 1; b >= 0; b -= len) {
            ll c = 0;
            for (int i = max(b - len + 1, 0); i <= b; i++)
                c = 10 * c + s[i] - '0';
            d.push_back(c);
        }
    }

    int size() const {return d.size();}

    Int operator + (const Int& a) {
        Int c;
        ll carry = 0;
        for (int i = 0; i < size() || i < a.size(); i++) {
            ll s = (i < size() ? d[i] : 0) + (i < a.size() ? a.d[i] : 0) + carry;
            if (carry = s / base)
                s %= base;
            c.d.push_back(s);
        }
        return c;
    }

    Int operator += (const Int& a) {
        return *this = *this + a;
    }

    Int operator * (const Int& a) {
        Int r;
        for (int i = 0; i < size(); i++) {
            if (!d[i])
                continue;
            ll carry = 0;
            for (int j = 0; j < a.size(); j++) {
                while (i+j >= r.size())
                    r.d.push_back(0);
                r.d[i+j] += a.d[j] * d[i] + carry;
                carry = r.d[i+j] / base;
                r.d[i+j] %= base;
            }
            if (carry)
                r.d.push_back(carry);
        }
        return r;
    }

    Int operator *= (const Int& a) {
        return *this = *this * a;
    }

    bool operator < (const Int& a) const {
        if (size() != a.size())
            return size() < a.size();
        for (int i = size() - 1; i >= 0; i--)
            if (d[i] != a.d[i])
                return d[i] < a.d[i];
        return false;
    }

    bool operator > (const Int& a) const {
        return a < *this;
    }
    
    bool operator == (const Int& a) const {
        if (size() != a.size())
            return false;
        for (int i = 0; i < size(); i++)
            if (d[i] != a.d[i])
                return false;
        return true;
    }
};

ostream& operator << (ostream& out, const Int& a) {
    out << a.d.back();
    for (int i = a.d.size() - 2; i >= 0; i--)
        out << setw(Int::len) << setfill('0') << a.d[i];
    return out;
}

Int qpow(int x, int n) {
    Int v(x), r(1);
    for (int p = 1; p <= n; p <<= 1, v *= v)
        if (p & n)
            r *= v;
    return r;
}

int main()
{
    int n;
    string buf;
    while (cin >> n >> buf) {
        Int v(buf);
#ifdef PP
cout << v << '\n';
#endif
        int low = 1, mid, high = MAXV;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            Int t = qpow(mid, n);
#ifdef PP
cout << "mid = " << mid << '\n';
cout << "t = " << t << '\n';
#endif
            if (t > v)
                high = mid - 1;
            else if (t < v)
                low = mid + 1;
            else
                break;
        }
        printf("%d\n", mid);
    }
    return 0;
}
