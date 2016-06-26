#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

const int sign[2] = {-1, 1};
const char c[2] = {'a', 'z'};

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n && k; i++) {
        int a = 0, ch;
        for (int j = 0; j <= 1; j++) {
            int t = abs(c[j] - s[i]);
            if (t > a) {
                a = t;
                ch = j;
            }
        }
        a = min(a, k);
        k -= a;
        s[i] += sign[ch] * a;
    }
    if (k)
        cout << "-1\n";
    else
        cout << s << '\n';

    return 0;
}
