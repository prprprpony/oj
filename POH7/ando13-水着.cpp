#include <iostream>
using namespace std;
const int maxn = 1000000 + 5;
const unsigned long long M = 10000000000000;
const unsigned long long L = 1000000000;
unsigned long long a[maxn];
int main()
{
    int n;
    cin >> n;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] * i;
        while (a[i] % 10 == 0)
            a[i] /= 10;
        a[i] %= M;
    }
    cout << a[n] % L << '\n';
    return 0;
}
