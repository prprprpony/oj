#include <cstdio>
#include <ctime>
#include <cstdlib>
#define MAXN 100000

struct Treap
{
    int key;
    int pri;
    int sz;
    Treap *l, *r;
    Treap(int v = 0) : key(v), pri(rand()), sz(1), l(NULL), r(NULL) {}
};

Treap mempool[MAXN];
Treap* ptr;

inline void clear() {
    ptr = mempool;
}

inline Treap* New(int v) {
    *ptr = Treap(v);
    return ptr++;
}

inline int Sz(Treap* t) {
    return t != NULL ? t->sz : 0;
}

inline void pull(Treap* t) {
    t->sz = 1 + Sz(t->l) + Sz(t->r);
}

Treap* merge(Treap* a, Treap* b) {
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (a->pri > b->pri) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

void split(Treap *t, int k, Treap*& a, Treap*& b) {
    if (t == NULL) {
        a = b = NULL;
    } else if (t->key <= k) {
        a = t;
        split(t->r, k, a->r, b);
        pull(a);
    } else {
        b = t;
        split(t->l, k, a, b->l);
        pull(b);
    }
}

int main()
{
    srand(42);
    int n, m;
    Treap* root;
    Treap *l, *r;

    while (scanf("%d", &n) == 1) {
        clear();
        root = NULL;
        while (n--) {
            scanf("%d", &m);
            split(root, m, l, r);
            printf("%d\n", Sz(r) + 1);
            root = merge(merge(l, New(m)), r);
        }
    }
    return 0;
}
