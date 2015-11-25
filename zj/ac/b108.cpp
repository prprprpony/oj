#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e4;
int d[maxn]; // distance to last fork
int r[maxn];
int lf[maxn]; // lf[i]: last fork from root to i
int l2[maxn][2]; // l2[root]: two longest paths from root
int deg[maxn];
int main()
{
    int n;
    while (cin >> n) {
        int ans = 0;
        for (int i = 0; i < n ; i++) {
            r[i] = i;
            lf[i] = -1;
            d[i] = 0;
            l2[i][0] = l2[i][1] = 0;
        }
        for (int i = 0, a; i < n; i++) {
            vector<int> childs;
            while (cin >> a && a > 0)
                childs.push_back(a);
            switch (childs.size()) {
            case 0: { // i is a leaf
                int j = i, nd = d[i];
                for ( ; lf[j] != -1 && nd > l2[lf[j]][1]; j = lf[j], nd += d[j]) {
                    l2[lf[j]][1] = nd;
                    ans = max(ans, l2[lf[j]][0] + l2[lf[j]][1]);
                    if (l2[lf[j]][1] > l2[lf[j]][0]) {
                        swap(l2[lf[j]][1], l2[lf[j]][0]);
                    } else {
                        break;
                    }
                }
                if (lf[j] ==  -1 && j != r[j] && nd > l2[r[j]][0]) {
                    ans = max(ans, l2[r[j]][0] = nd);
                }
                break;
            }
            case 1: {
                vector<int>::iterator it = childs.begin();
                lf[*it] = lf[i];
                r[*it] = r[i];
                d[*it] = d[i] + 1;
                break;
            }
            default: { // i is a fork
                for (vector<int>::iterator it = childs.begin(); it != childs.end(); it++) {
                    lf[*it] = i;
                    r[*it] = r[i];
                    d[*it] = 1;
                }
                break;
            }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
