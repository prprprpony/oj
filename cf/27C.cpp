#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
int a[N],pomn[N],pomx[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    pomn[n-1] = pomx[n-1] = n-1;
    for (int i = n-2; i >= 0; --i) {
        pomn[i] = a[i] < a[pomn[i+1]] ? i : pomn[i+1];
        pomx[i] = a[i] > a[pomx[i+1]] ? i : pomx[i+1];
    }
    int mn,mx;
    mn=mx=0;
    for (int i = 1; i <= n - 2; ++i) {
        if (a[mn] < a[i] && a[pomn[i+1]] < a[i]) {
            cout << "3\n" << mn+1 << ' ' << i+1 <<  ' ' << pomn[i+1]+1 << '\n';
            return 0;
        }
        if (a[mx] > a[i] && a[pomx[i+1]] > a[i]) {
            cout << "3\n" << mx+1 << ' ' << i+1 <<  ' ' << pomx[i+1]+1 << '\n';
            return 0;
        }
        if (a[i] > a[mx])
            mx = i;
        if (a[i] < a[mn])
            mn = i;
    }
    cout << "0\n";
}
