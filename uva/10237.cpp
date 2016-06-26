#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
// vector<long long> ways[2];
int main()
{
    long long ans;
    int n, k;
    vector<long long> ways[2];
    // long long ways[2][65];
    while (cin >> n >> k && n > 0) {
        if (k > 2 * n - 1) {
            cout << "0\n";
            continue;
        }
        else if (n == 1) {
            cout << "1\n";
            continue;
        }

        for (int c = 0; c <= (n & 1); c++) {
            ways[c].resize(k + 1);
            ways[c][0] = 1;
            ways[c][1] = 1 + c;
            for (int i = 2; i <= k; i++)
                ways[c][i] = 0;
            for (int i = 1; i < n - c; i++)
                for (int j = min(i + 1, k); j >= 1; j--)
                    ways[c][j] = ways[c][j] + ((i / 2 * 2 + 1 + c) - (j - 1)) * ways[c][j - 1];
        }

        ans = 0;
        for (int i = 0; i <= k; i++)
            ans += ways[0][i] * ways[n & 1][k - i];
        cout << ans << '\n';
    }
    return 0;
}
