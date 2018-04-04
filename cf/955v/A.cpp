#include<bits/stdc++.h>
using namespace std;
int main()
{
    int hh,mm;
    cin >> hh >> mm;
    int t = hh * 60 + mm;
    long long h,d,c,n;
    cin >> h >> d >> c >> n;
    double ans = (h+n-1) / n * c;
    int x = max(0, 20 * 60 - t);
    ans = min(ans, (h+x*d+n-1) / n * c * 0.8);
    cout << ans << endl;
}
