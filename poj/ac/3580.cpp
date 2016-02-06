#include <cstdio>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <queue>
#define MAXN 800000
#define INF 2147483647
using namespace std;
struct treap
{
    int v;
    int sz;
    int p;
    int mn;
    int rev;
    int add;
    treap *l, *r;
    treap() {}
    treap(int k) : v(k), sz(1), p(rand()), mn(k), rev(0), add(0), l(NULL), r(NULL) {}
};

treap mempool[MAXN];
treap* ptr;
treap* gc; // use treap as linked list to garbage collect

inline void init() {
    ptr = mempool;
    gc = NULL;
}

inline void Del(treap* t) {
    t->l = gc;
    gc = t;
}

inline treap* New(int v) {
    if (gc == NULL) {
        *ptr = treap(v);
        return ptr++;
    } else {
        treap* t = gc;
        gc = gc->l;
        *t = treap(v);
        return t;
    }
}

inline int size(treap* t) {
    return t != NULL ? t->sz : 0;
}

inline int small(treap* t) {
    return t != NULL ? t->mn + t->add : INF;
}

inline void pull(treap* t) {
    if (t == NULL)
        return;
    t->sz = 1 + size(t->l) + size(t->r);
    t->mn = min(t->v, min(small(t->l), small(t->r)));
}

inline void reverse(treap* t) {
    if (t != NULL)
        t->rev ^= 1;
}

inline void addn(treap* t, int v) {
    if (t != NULL)
        t->add += v;
}

inline treap* push(treap* t) {
    if (t != NULL) {
        if (t->rev) {
            swap(t->l, t->r);
            reverse(t->l);
            reverse(t->r);
            t->rev = 0;
        }

        if (t->add) {
            t->v += t->add;
            t->mn += t->add;
            addn(t->l, t->add);
            addn(t->r, t->add);
            t->add = 0;
        }
    }
    return t;
}

void split(treap* t, int k, treap*& a, treap*& b) { // split first k nodes from t to a, others to b
    push(t);

    if (t == NULL) {
        a = b = NULL;
    } else if (size(t->l) + 1 <= k) {
        a = t;
        split(t->r, k - size(t->l) - 1, a->r, b);
        pull(a);
    } else {
        b = t;
        split(t->l, k, a, b->l);
        pull(b);
    }
}

treap* merge(treap* a, treap* b) {
    if (a == NULL)
        return push(b);
    else if (b == NULL)
        return push(a);
    if (a->p > b->p) {
        push(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        push(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

inline void slice(treap* t, int x, int y, treap*& l, treap*& m, treap*& r) {
    split(t, x - 1, l, r);
    split(r, y - x + 1, m, r);
}

treap* build(int n) {
    treap* r = NULL;
    int v;
    stack<treap*> rc;
    treap* nt;
    while (n--) {
        scanf("%d", &v);
        nt = New(v);
        r = NULL;
        while (!rc.empty() && rc.top()->p < nt->p) {
            pull(r = rc.top());
            rc.pop();
        }
        nt->l = r;
        if (!rc.empty())
            rc.top()->r = nt;
        rc.push(nt);
    }
    while (!rc.empty()) {
        pull(r = rc.top());
        rc.pop();
    }
    return r;
}

int main()
{
    srand(42);
    int n, q;
    char cmd[10];
    int x, y, v;
    treap *l, *m, *r;
    treap *ml, *mr;
    treap* root;

    while (scanf("%d", &n) == 1) {
        init();
        root = build(n);
        scanf("%d", &q);
        while (q--) {
            scanf("%s", cmd);
            switch (cmd[0]) {
            case 'A':
                scanf("%d%d%d", &x, &y, &v);
                slice(root, x, y, l, m, r);
                addn(m, v);
                root = merge(merge(l, m), r);
                break;
            case 'I':
                scanf("%d%d", &x, &v);
                split(root, x, l, r);
                root = merge(merge(l, New(v)), r);
                break;
            case 'D':
                scanf("%d", &x);
                slice(root, x, x, l, m, r);
                Del(m);
                root = merge(l, r);
                break;
            case 'M':
                scanf("%d%d", &x, &y);
                slice(root, x, y, l, m, r);
                printf("%d\n", m->mn);
                root = merge(merge(l, m), r);
                break;
            case 'R':
                scanf("%d%d", &x, &y);
                switch (cmd[3]) {
                case 'E':
                    slice(root, x, y, l, m, r);
                    reverse(m);
                    root = merge(merge(l, m), r);
                    break;
                case 'O':
                    scanf("%d", &v);
                    int len = (y-x+1);
                    v = (v % len + len) % len; // v could be negative?
                    if (v) {
                        slice(root, x, y, l, m, r);
                        split(m, len-v, ml, mr);
                        root = merge(merge(l, merge(mr, ml)), r);
                    }
                    break;
                }
                break;
            }
        }
    }
    return 0;
}
