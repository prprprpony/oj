#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 87;
int a[N], s[N], k[N], tp;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        k[i] = min(i - (-1), n - i);
        cin >> a[i];
        while (tp && a[i] < a[s[tp-1]])
            --tp;
        if (tp)
            k[i] = min(k[i], i - s[tp-1]);
        s[tp++] = i;
    }
    tp = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (tp && a[i] < a[s[tp-1]])
            --tp;
        if (tp)
            k[i] = min(k[i], s[tp-1] - i);
        s[tp++] = i; 
        ans += k[i];
    }
    cout << ans << '\n';
}
