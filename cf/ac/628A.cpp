#include <iostream>
using namespace std;

int p2(int n) {
    while (n & (n - 1))
        n ^= (-n & n);
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, b, p;
    cin >> n >> b >> p;
    int x = 0, y = n * p;
    while (n != 1) {
        int k = p2(n);
        x += k / 2 * (b * 2 + 1);
        n -= k / 2;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}
