#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if (a >= 13)
        cout << (((1LL << 13) - 100) << (a - 13));
    else
        cout << (1LL << a);
    cout << '\n';
    return 0;
}
