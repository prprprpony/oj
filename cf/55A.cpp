#include <bits/stdc++.h>
using namespace std;
const int N = 1087;
bitset<N> ok;
int main()
{
    int n;
    cin >> n;
    for (int i = 0, k = 0; i < 2 * n; ++i) {
        k = (k + i) % n;
        ok[k] = 1;
    }
    cout << (ok.count() == n ? "YES" : "NO") << endl;
}
