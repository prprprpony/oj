#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int c[26] = {};
    for (char x : s)
        ++c[x - 'a'];
    sort(c,c+26,greater<int>());
    if (c[4] > 0) {
        cout << "No\n";
        return 0;
    }
    if (c[3] > 0) {
        cout << "Yes\n";
        return 0;
    }
    if (c[2] > 0) {
        bool ok = 0;
        for (int i = 0; i < 3; ++i)
            ok |= c[i] > 1;
        cout << (ok ? "Yes\n" : "No\n");
        return 0;
    }
    cout << (c[0] > 1 && c[1] > 1 ? "Yes\n" : "No\n");
}
