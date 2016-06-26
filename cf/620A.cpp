#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << max(abs(x - a), abs(y - b)) << '\n';
    return 0;
}
