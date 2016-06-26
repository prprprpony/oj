#include <iostream>
#include <algorithm>
#define MAXN 100000
#define INF 1000000426
using namespace std;
int a[MAXN];
int main()
{
    int t, n, s;
    int ans;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ans = INF;
        for (int l = 0, r = 0, sum = 0; l < n; l++) {
            if (r < l)
                r = l;
            while (r < n && sum < s)
                sum += a[r++];
            if (sum >= s) {
                ans = min(ans, r - l);
                sum -= a[l];
            } else  {
                break;
            }
        }
        cout << (ans != INF ? ans : 0) << '\n';
    }
}
