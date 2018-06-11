#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87;
int a[N], la[20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long ans = 0;
    int pr = -1;
    fill_n(la,20,-1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0, x = a[i]; j < 20; ++j, x>>=1)
            if (x&1) {
                pr = max(pr, la[j]);
                la[j] = i;
            }
        ans += i - pr;
    }
    cout << ans << endl;
}
