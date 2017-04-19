#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 414;
map<int,int> m;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while ((cin >> n) && n) {
        m.clear();
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++m[a];
        }
        int ans = 0, sum = 0;
        for (auto i = m.begin(); i != m.end(); ++i) {
            ans += i->second * sum;
            sum += i->second;
        }
        static int kase = 0;
        cout << "Case " << ++kase << ": " << ans << '\n';
    }
}
