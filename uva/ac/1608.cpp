#include <cstdio>
#include <cstring>
#include <map>
#define MAXS 200005
using namespace std;

int n;
int s[MAXS];
int l[MAXS];
int r[MAXS];
map<int, int> last;

bool unique(int i, int a, int e) {
    return (l[i] == -1 || l[i] < a) && (r[i] == -1 || r[i] >= e);
}

bool non_boring(int a, int e)
{
    if (a == e || a + 1 == e)
        return true;
    for (int i = a, j = e-1; i <= j; ++i, --j) {
        if (unique(i, a, e))
            return non_boring(a, i) && non_boring(i+1, e);
        if (unique(j, a, e))
            return non_boring(a, j) && non_boring(j+1, e);
    }
    return false;
}

int main()
{
    int t;
    int i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        last.clear();
        memset(l, -1, n * sizeof(int));
        memset(r, -1, n * sizeof(int));
        for (i = 0; i < n; ++i) {
            scanf("%d", &s[i]);
            if (last.find(s[i]) != last.end()) {
                l[i] = last[s[i]];
                r[last[s[i]]] = i;
            }
            last[s[i]] = i;
        }
        printf(non_boring(0, n) ? "non-boring\n" : "boring\n");
    }

    return 0;
}
