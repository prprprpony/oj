#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 50;
struct Int
{
    const static long long base = 1e9;
    vector<long long> digit;

    Int()
    {
        digit.clear();
    }

    Int operator = (long long x)
    {
        digit.clear();
        do {
            digit.push_back(x % base);
            x /= base;
        } while(x);
        return *this;
    }

    Int operator = (const Int &x)
    {
        digit = x.digit;
        return *this;
    }

    Int operator + (const Int &x)
    {
        Int c;
        for (int i = 0; i < x.digit.size() || i < digit.size(); i++)
            c.digit.push_back((i < x.digit.size() ? x.digit[i] : 0) + (i < digit.size() ? digit[i] : 0));
        for (int i = 0; i < c.digit.size() - 1; i++) {
            c.digit[i+1] += c.digit[i] / base;
            c.digit[i] %= base;
        }
        while (c.digit.back() >= base) {
            c.digit.push_back(c.digit.back() / base);
            c.digit[c.digit.size() - 2] %= base;
        }
        return c;
    }

    friend ostream& operator <<(ostream &out, const Int &x) {
        out.width(0);
        out << x.digit.back();
        out.width(9);
        out.fill('0');
        for (int i = x.digit.size() - 2; i >= 0; i--)
            out << x.digit[i];
        out.width(0);
        return out;
    }

};

int main()
{
    int n;
    Int d[maxn][3];
    for (int i = 0; i < 3; i++)
        d[0][i] = 1;
    for (int i = 1; i < maxn; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0] + d[i-1][1] + d[i-1][2];
        d[i][2] = d[i-1][1] + d[i-1][2];
    }
    while (scanf("%d", &n) == 1) {
        cout << d[n-1][0] + d[n-1][1] + d[n-1][2] << '\n';
    }

    return 0;
}
