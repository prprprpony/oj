#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,c=1,a,ans = 0;
    cin >> n >> a;
    for (int i = 1; i < n; ++i) {
        long long b;
        cin >> b;
        if (b == a)
            ++c;
        else {
            ans += c * (c+1) / 2;
            c = 1;
            a = b;
        }
    }
    ans += c * (c+1) / 2;
    cout << ans << endl;
}
