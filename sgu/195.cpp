#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 +87;
int de[N],pa[N];
vector<int> ly[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i > 1)
            cin >> pa[i];
        de[i] = de[pa[i]] + 1;
        ly[de[i]].push_back(i);
    }
    int ans = 0;
    for (int d = n; d >= 1; --d) {
        for (int u : ly[d]) {
            if (de[u] > 0 && de[pa[u]] > 0) {
                de[u] = -1;
                de[pa[u]] = -2;
                ++ans;
            }
        }
    }
    cout << ans * 1000 << '\n';
    for (int i = 1; i <= n; ++i)
        if (de[i] == -1)
            cout << i << " \n"[--ans==0];
}
