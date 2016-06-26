#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
struct Int {
    const static ll base = 1e9;
    const static int width = 9;
    vl d;

    Int()
    {
        d.clear();
    }

    Int(ll a)
    {
        do {
            d.push_back(a % base);
            a /= base;
        } while (a);
    }

    Int(const string &s)
    {
        ll t;
        for (int i =  s.size() - 1; i >= 0; i -= width) {
            t = 0;
            for (int j = min(width - 1, i); j >= 0; j--) {
                t = 10 * t + s[i-j] - '0';
            }
            d.push_back(t);
        }
    }

    Int operator = (const Int& a)
    {
        this->d = a.d;
        return a;
    }

    Int operator = (int a)
    {
        return *this = Int(a);
    }

    Int operator + (const Int& a)
    {
        Int c;
        ll carry = 0;
        ll v;
        int i;
        for (i = 0; i < d.size() && i < a.d.size(); i++) {
            v = a.d[i] + d[i] + carry;
            carry = v / base;
            v %= base;
            c.d.push_back(v);
        }
        for ( ; i < d.size(); i++) {
            v = d[i] + carry;
            carry = v / base;
            v %= base;
            c.d.push_back(v);
        }
        for ( ; i < a.d.size(); i++) {
            v = a.d[i] + carry;
            carry = v / base;
            v %= base;
            c.d.push_back(v);
        }
        if (carry)
            c.d.push_back(carry);
        return c;
    }

    Int operator + (const ll& a)
    {
        return *this + Int(a);
    }

    Int operator += (const Int& a)
    {
        return *this = *this + a;
    }

    Int operator - (int a) // *this > a && a < base
    {
        Int c = *this;
        c.d[0] -= a;
        for (int i = 0; i < c.d.size() - 1 && c.d[i] < 0; i++) {
            c.d[i] += base;
            c.d[i+1]--;
        }
        while (c.d.size() > 1 && c.d[c.d.size()-1] == 0)
            c.d.pop_back();
        return c;
    }

    Int operator * (const Int& a)
    {
        if (d.size() == 1 && d[0] == 0)
            return *this;

        Int ret = 0;
        Int b;
        Int t;
        ll carry;

        for (int i = 0; i < a.d.size(); i++) {
            if (a.d[i]) {
                t = b;
                for (int j = 0; j < d.size(); j++)
                    t.d.push_back(d[j] * a.d[i]);
                carry = 0;
                for (int j = b.d.size(); j < t.d.size(); j++) {
                    t.d[j] += carry;
                    carry = t.d[j] / base;
                    t.d[j] %= base;
                }
                if (carry)
                    t.d.push_back(carry);
                ret += t;
            }
            b.d.push_back(0);
        }

        return ret;
    }
};

ostream& operator << (ostream& out, const Int& a)
{
    int i = a.d.size() - 1;
    out << a.d[i--];
    for ( ; i >= 0; i--)
        out << setw(Int::width) << setfill('0') << a.d[i];
    return out;
}

int main()
{
    Int n;
    string buf;
    while (cin >> buf) {
        if (buf.size() == 1 && buf[0] == '0') {
            puts("1");
            continue;
        }
        n = Int(buf);
        cout << n * (n - 1) + 2 << '\n';
    }
}
