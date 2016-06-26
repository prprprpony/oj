#include <iostream>
using namespace std;
long long n;
int main()
{
    while (cin >> n && n >= 0)
        cout << 1 + (n + 1) * n / 2 << '\n';
    return 0;
}
