#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+87;
int x[N],z,n;
bool ok(int k)
{
    for (int i = 0; i < k; ++i)
        if (x[n-k+i] - x[i] < z)
            return false;
    return true;
}
int main()
{
    cin >> n >> z;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x,x+n);
    int lo = 0, hi = n/2;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (ok(mi))
            lo = mi + 1;
        else
            hi = mi - 1;
    }
    cout << hi << endl;
}
