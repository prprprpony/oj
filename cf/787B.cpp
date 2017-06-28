#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    bool ok = true;
    while (m--) {
        int k;
        cin >> k;
        set<int> s;
        while (k--) {
            int v;
            cin >> v;
            s.insert(v);
        }
        bool f = false;
        for (int v : s)
            if (s.count(-v)) {
                f = true;
                break;
            }
        if (!f) {
            ok=false;
            break;
        }
    }
    cout << (ok ? "No\n" : "Yes\n");
}
