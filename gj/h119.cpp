#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int maxi = 99999 + 5;
long long item[maxi];
int t, s, n;
long long cost;
int main()
{
    scanf("%d", &t);
    while (t--) {
        memset(item, -1, sizeof(item));
        set<int> ans;
        scanf("%d%d ", &s, &n);
        for (int i = 0, id, p; i < s; i++) {
            scanf("item%d $%d ", &id, &p);
            item[id] = p;
        }
        for (int i = 0, id, p, m, it; i < n; i++) {
            scanf("food%d $%d : ", &id, &p);
            cost = 0;
            do {
                scanf("%d item%d", &m, &it);
                if (cost != -1) {
                    if(item[it] != -1)
                        cost += m * item[it];
                    else
                        cost = -1;
                    if (cost > p)
                        cost = -1;
                }
            } while (getchar() == ' ');
            if (cost != -1 && p > cost)
                ans.insert(id);
        }
        if (ans.size() > 0) {
            bool first = true;
            for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
                if (!first)
                    putchar('/');
                else
                    first = false;
                printf("food%d", *it);
            }
            putchar('\n');
        } else {
            puts("no such recipe.");
        }
    }

    return 0;
}
