#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+87;
int n;
string s[N];
vector<int> g[N][5];
const string w = "aeiou";
int f(char c)
{
    for (int i = 0; i < 5; ++i)
        if (c == w[i])
            return i;
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int la = -1;
        int k = 0;
        for (char c : s[i]) {
            int j = f(c);
            if (j >= 0)
                ++k, la = j;
        }
        g[k][la].push_back(i);
    }
    vector<pair<int,int>> a,b;
    for (int i = 1; i < N; ++i) {
        int x=-1;
        for (int j = 0; j < 5; ++j) {
            int y=-1;
            for (int k : g[i][j]) {
                if (y == -1)
                    y = k;
                else
                    b.emplace_back(y,k), y = -1;
            }
            if (x == -1)
                x = y;
            else if (y != -1)
                a.emplace_back(x,y), x =-1;
        }
    }
    int ans = min(a.size(),b.size());
    ans += (b.size() - ans) / 2;
    cout << ans << '\n';
    while (a.size() && b.size()) {
        auto x = a.back(), y = b.back();
        a.pop_back(), b.pop_back();
        cout << s[x.first] << ' ' << s[y.first] << '\n';
        cout << s[x.second] << ' ' << s[y.second] << '\n';
    }
    while (b.size() >= 2) {
        auto x = b.back();
        b.pop_back();
        auto y = b.back();
        b.pop_back();
        cout << s[x.first] << ' ' << s[y.first] << '\n';
        cout << s[x.second] << ' ' << s[y.second] << '\n';
    }
}
