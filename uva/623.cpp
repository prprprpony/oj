#include <bits/stdc++.h>
using namespace std;

struct Int
{
    static const long long base = 1000000000;
    static const int width = 9;
    vector<long long> digits;
    Int operator = (int a) {
        digits.clear();
        do {
            digits.push_back(a % base);
            a /= base;
        } while (a);
        return *this;
    }
    Int operator * (int a) const {
        Int t = *this;
        long long carry = 0;
        for (int i = 0; i < t.digits.size(); i++) {
            t.digits[i] = t.digits[i] * a + carry;
            carry = t.digits[i] / base;
            t.digits[i] %= base;
        }
        if (carry)
            t.digits.push_back(carry);
        return t;
    }
};

ostream& operator << (ostream &out, const Int &a) {
    out << a.digits.back();
    for (int i = a.digits.size() - 2; i >= 0; i--)
        out << setw(Int::width) << setfill('0') << a.digits[i];
    return out;
}

const int maxn = 1001;
Int factorial[maxn];

int main()
{
    int n;
    factorial[0] = 1;
    for (int i = 1; i < maxn; i++)
        factorial[i] = factorial[i-1] * i;
    while (cin >> n)
        cout << n << "!\n" <<  factorial[n] << '\n';
    return 0;
}
