#include <iostream>
using namespace std;
int main()
{
    long long a[61];
    int q, kase = 0;
    a[1] = a[2] = a[3] = 1;
    for (int i = 4; i < 61; i++)
        a[i] = a[i-1] + a[i-2] + a[i-3];
    while (cin >> q && q > 3)
        cout << "Case " << ++kase << ": " << a[q] << '\n';
    return 0;
}
