#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    int x, y, z, n;
    int d, a;
    cin >> x >> y >> z >> n;
    int mr = x, mc = y;
    bool r[x + 1], c[y + 1];
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    r[x] = r[y] = true;
    while (n--) {
        cin >> d >> a;
        if (d)
            c[a] = true;
        else
            r[a] = true;
    }
    for (int i = 1, last = 0; i <= x; i++)
        if (r[i]) {
            mr = min(mr, i - last);
            last = i;
        }
    for (int i = 1, last = 0; i <= y; i++)
        if (c[i]) {
            mc = min(mc, i - last);
            last = i;
        }
    cout << mr * mc * z << '\n';

    return 0;
}
