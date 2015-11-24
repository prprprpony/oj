#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2005;
struct bug
{
    int root; // index of its root
    int size; // if it's root, the number of nodes on this tree
    bool same; // its sex is the same as its root's or not
};
bug b[maxn];
int find(int x)
{
    if (b[x].root == x) {
        return x;
    } else {
        int p = b[x].root;
        b[x].root = find(p);
        b[x].same = b[x].same ? b[p].same : !b[p].same;
        return b[x].root;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases++) {
        int n, m;
        bool fail = false;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            b[i].root = i;
            b[i].size = 1;
            b[i].same = true;
        }
        for (int i = 0, a, c, ra, rc; i < m; i++) {
            cin >> a >> c;
            if (!fail) {
                ra = find(a);
                rc = find(c);
                if (ra != rc) {
                    if (b[rc].size > b[ra].size)
                        swap(ra, rc);
                    b[rc].root = ra;
                    b[rc].same = b[c].same == b[a].same ? false : true;
                    b[ra].size += b[rc].size;
                } else if (b[a].same == b[c].same) {
                    fail = true;
                }
            }
        }
        cout << "Scenario #" << cases << ":\n";
        cout << (fail ? "Suspicious bugs found!" : "No suspicious bugs found!") << "\n\n";
    }

    return 0;
}
