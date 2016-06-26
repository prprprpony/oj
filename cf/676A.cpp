#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mxp, mnp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1)
            mnp = i;
        else if (a == n)
            mxp = i;
    }
    cout << max(n - 1 - min(mxp, mnp), max(mxp, mnp) - 0) << '\n';
}
