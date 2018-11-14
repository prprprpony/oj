#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> v;
    for (int i = 0; i < 4; ++i) {
        v.resize(i+1);
        for (int j = 0; j < n; ++j) {
            string s;
            cin >> s;
            v.back().emplace_back(s);
        }
    }
    sort(begin(v),end(v));
    int ans = INT_MAX;
    do {
        for (int x = 0; x <= 1; ++x) {
            int s = 0;
            for (int i = 0; i < 2 * n; ++i)
                for (int j = 0; j < 2 * n; ++j)
                    s += v[(i >= n)*2+(j>=n)][i%n][j%n]-'0' != ((i^j^x)&1);
            ans = min(ans, s);
        }
    } while (next_permutation(begin(v),end(v)));
    cout << ans << endl;
}
