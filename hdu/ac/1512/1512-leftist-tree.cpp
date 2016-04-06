#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 228;

struct node
{
    int v;
    int s;
    node* lc;
    node* rc;
    node() {}
    node(int k) : v(k), s(1), lc(NULL), rc(NULL) {}
};

node mem[maxn];
node* ptr;
node* h[maxn];

inline void clear() {
    ptr = mem;
}

inline int top(node* t) {
    return t->v;
}

inline int S(node* t) {
    return t ? t->s : 0;
}

node* meld(node* a, node* b) {
    if (!a || !b)
        return a ? a : b;
    if (a->v < b->v)
        swap(a, b);
    a->rc = meld(a->rc, b);
    if (S(a->lc) < S(a->rc))
        swap(a->lc, a->rc);
    a->s = S(a->rc) + 1;
    return a;
}

int p[maxn];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}

int main(void)
{
    int n, m;
    while (scanf("%d", &n) == 1) {
        clear();
        for (int i = 1; i <= n; i++) {
            h[i] = ptr++;
            int k;
            scanf("%d", &k);
            *h[i] = node(k);
            p[i] = i;
        }
        scanf("%d", &m);
        while (m--) {
            int x[2];
            for (int i = 0; i <= 1; i++) {
                scanf("%d", x + i);
                x[i] = find(x[i]);
            }
            if (x[0] != x[1]) {
                for (int i = 0; i <= 1; i++) {
                    node* tmp = meld(h[x[i]]->lc, h[x[i]]->rc);
                    *h[x[i]] = node(h[x[i]]->v / 2);
                    h[x[i]] = meld(tmp, h[x[i]]);
                }
                h[x[0]] = meld(h[x[0]], h[x[1]]);
                p[x[1]] = x[0];
                printf("%d\n", top(h[x[0]]));
            } else {
                puts("-1");
            }
        }
    }
    return 0;
}
