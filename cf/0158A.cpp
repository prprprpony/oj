#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int first = -1;
    int last = -1;
    for (int i = 1, a, ak = -1; i <= n; i++) {
        cin >> a;
        if (first == -1 && a > 0)
            first = i;
        if (i == k)
            ak = a;
        if ((a > 0 && i <= k) || (ak > 0 && a == ak))
            last = i;
    }
    if (first != -1 && last != -1)
        cout << last - first + 1 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}
