#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    bool b[10] = {};
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        b[a] = 1;
    }
    while (1) {
        int x = n;
        bool ok = 1;
        for (;x && ok;x/=10)
            ok = !b[x%10];
        if (ok)
            break;
        ++n;
    }
    cout << n << '\n';
}
