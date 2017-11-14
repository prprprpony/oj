#include<bits/stdc++.h>
using namespace std;
const int N = 1.1e6, M = 1e9 + 7;
char s[N];
int a[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> s;
    int n = strlen(s), c = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'b')
            ++c;
        else {
            ans += c;
            c *= 2;
            while (c >= M)
                c -= M;
        }
    }
    cout << ans % M << '\n';
}
