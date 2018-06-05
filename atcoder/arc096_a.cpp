#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (2 * c <= a + b) {
        int t = min(x,y);
        x -= t, y -= t;
        ans += t * 2 * c;
    }
    if (2 * c <= a) {
        ans += 2 * c * x;
        x = 0;
    }
    if (2 * c <= b) {
        ans += 2 * c * y;
        y = 0;
    }
    ans += a * x + b * y;
    cout << ans << endl;
}
