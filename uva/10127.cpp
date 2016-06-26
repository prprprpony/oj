#include <iostream>
using namespace std;
int main()
{
    int a, i, m;
    while (cin >> a) {
        for (i = 1, m = 1 % a; m > 0; i++, m = (10 * m + 1) % a); // X[i] = 10 * X[i-1] + 1,  X[i] % a == 0 -> (10 * (X[i-1] % a) + 1) % a == 0
        cout << i << '\n';
    }
    return 0;
}
