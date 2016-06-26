#include <iostream>
using namespace std;
int nxt[55];
int main()
{
    int n, x, cases = 0;
    while (cin >> n) {
        cin >> x;
        for (int i = 0; i < 55; i++)
            nxt[i] = i < n ? i + 1 : -1;
        bool finished = false;
        for (int i = 0, left = n, m; i < 20; i++) {
            cin >> m;
            if (!finished && m <= left) {
                if (m != 1) {
                    for (int it = 0, cnt = 0; it != -1 && nxt[it] != -1 && left > x; it = nxt[it], cnt++) {
                        if (cnt == m - 1) {
                            cnt = 0;
                            left--;
                            nxt[it] = nxt[nxt[it]];
                        }
                    }
                } else {
                    int it;
                    for (it = nxt[0]; left > x; it = nxt[it], left--);
                    nxt[0] = it;
                }
                if (left == x)
                    finished = true;
            }
        }
        cout << "Selection #" << ++cases << '\n';
        for (int it = nxt[0]; it != -1; it = nxt[it])
            cout << it << (nxt[it] != -1 ? ' ' : '\n');
        cout << '\n';
    }

    return 0;
}
