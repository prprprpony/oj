#include<bits/stdc++.h>
using namespace std;
const int N = 1<<18;
int s[N],vis[N],n,x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        s[a] = 1;
    }
    vector<int> cur = {0};
    vis[0] = 1;
    for (int i = 1; i < N; ++i)
        if (s[i] && !vis[i]) {
            for (int j = cur.size() - 1; j >= 0; --j) {
                int k = i ^ cur[j];
                vis[k] = 1;
                cur.push_back(k);
            }
            if (cur.size() == (2<<__lg(i)))
                x = __lg(i) + 1;
        }
    cout << x << '\n';
    for (int i = 0; i < (1<<x); ++i)
        cout << cur[i] << " \n"[i+1==(1<<x)];
}
