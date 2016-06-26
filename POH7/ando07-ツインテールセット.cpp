#include <iostream>
using namespace std;
int main(void)
{
    int ans = 1;
    double c, p, r;
    cin >> c >> p;
    r = c / p;
    cin >> c >> p;
    if (c / p > r)
        ans = 2;
    cout << ans << '\n';
    return 0;
}
