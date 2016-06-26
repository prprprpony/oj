#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int ans = 0;
    while (a) {
        if ((a & 7) == 1)
            ++ans;
        a >>= 3;
    }
    cout << ans << endl;
    return 0;
}
