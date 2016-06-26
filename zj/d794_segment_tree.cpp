#include <bits/stdc++.h>
#define MAXN 18446744073709551615ULL
using namespace std;
typedef unsigned long long ull;

struct Node
{
    int sum;
    Node *lc, *rc;
    Node() : sum(0), lc(NULL), rc(NULL) {}
    void pull() {
        sum = (lc ? lc->sum : 0) + (rc ? rc->sum : 0);
    }
    int eva(ull l, ull r, ull i, ull j) {
        if (r < i || l > j)
            return 0;
        if (i <= l && r <= j)
            return sum;
        ull m = l + ((r - l) >> 1);
        return (lc ? lc->eva(l, m, i, j) : 0) + (rc ? rc->eva(m + 1, r, i, j) : 0);
    }
};

Node* gc = NULL;
Node* New() {
    if (gc) {
        Node* t = gc;
        gc = gc->lc;
        *t = Node();
        return t;
    } else {
        return new Node();
    }
}
void Del(Node* t) {
    t->lc = gc;
    gc = t;
}

void add(Node* n, ull l, ull r, ull x, int v) {
    if (l == r) {
        n->sum += v;
        return;
    }
    ull m = l + ((r - l) >> 1);
    if (x <= m)
        add(n->lc ? n->lc : n->lc = New(), l, m, x, v);
    else
        add(n->rc ? n->rc : n->rc = New(), m + 1, r, x, v);
    n->pull();
}

void clear(Node* n) {
    if (n == NULL)
        return;
    clear(n->lc);
    clear(n->rc);
    Del(n);
}

int main()
{
    int n;
    ull m;
    Node* root = NULL;
    while (scanf("%d", &n) == 1) {
        clear(root);
        root = New();
        while (n--) {
            scanf("%ull", &m);
            printf("%d\n", root->eva(0, MAXN, m, MAXN) + 1);
            add(root, 0, MAXN, m, 1);
        }
    }
    return 0;
}
