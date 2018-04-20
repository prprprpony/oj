#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
int a[N],la[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    fill_n(la,k,-1);
    la[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= k;
        a[i] += a[i-1];
        a[i] %= k;
        int & j = la[a[i]];
        if (j != -1) {
            cout << i - j << '\n';
            while (++j <= i)
                cout << j << " \n"[j == i];
            return 0;
        }
        j = i;
    }
}
