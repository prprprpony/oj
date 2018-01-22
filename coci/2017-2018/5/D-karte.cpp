#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 87;
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a,a+n);
    rotate(a,a+n-k,a+n);
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (c < a[i])
            ++c;
    if (c != k) {
        cout << "-1\n";
        return 0;
    }
    for (int i = n - 1; i >= 0; --i)
        cout << a[i] << " \n"[i==0];
}
