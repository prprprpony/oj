#include <cstdio>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Treap
{
    int val;
    int pri;
    int size;
    int rev;
    Treap *l, *r;

    Treap(int v) : val(v), pri(rand()), size(1), rev(0), l(NULL), r(NULL) {}
};


inline int Size(Treap *t) {
    return t != NULL ? t->size : 0;
}

void reverse(Treap *t) {
    if (t != NULL)
        t->rev ^= 1;
}

void pull(Treap *t) {
    if (t != NULL)
        t->size = 1 + Size(t->l) + Size(t->r);
}

void push(Treap *t) {
    if (t != NULL && t->rev) {
        swap(t->l, t->r);
        reverse(t->l);
        reverse(t->r);
        t->rev = 0;
    }
}

void split(Treap *t, int k, Treap *&a, Treap *&b) { // split first k nodes from t to a, others to b
    if (k == 0) {
        a = NULL;
        b = t;
    } else if (t == NULL) {
        a = b = NULL;
    } else {
        push(t);
        if (Size(t->l) + 1 <= k) {
            a = t;
            split(t->r, k - Size(t->l) - 1, a->r, b);
            pull(a);
        } else {
            b = t;
            split(t->l, k, a, b->l);
            pull(b);
        }
    }
}

inline bool cmp(Treap *a, Treap *b) {
    return a->pri < b->pri;
}

Treap* merge(Treap *a, Treap * b) {
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (cmp(a, b)) {
        push(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    } else {
        push(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
}

Treap* build(int n) {
#ifdef EASYB // O(nlgn)
    Treap *r = NULL;
    for (int i = 1; i <= n; i++)
        r = merge(r, new Treap(i));
#else // linear build
    stack<Treap*> s;
    Treap *nt;
    Treap *r;
    for (int i = 1; i <= n; i++) {
        nt = new Treap(i);
        r = NULL;
        while (!s.empty()) {
            pull(s.top());
            if (cmp(s.top(), nt)) {
                r = s.top();
                s.pop();
            } else {
                break;
            }
        }
        nt->l = r;
        if (!s.empty())
            s.top()->r = nt;
        s.push(nt);
    }
    r = NULL;
    while (!s.empty()) {
        pull(r = s.top());
        s.pop();
    }
#endif
    return r;
}

#ifdef PT
void indent(int x) {
    while (x--)
        fputs("   ", stdout);
}
void print(Treap* t, int ind) {
    indent(ind);
    printf("v = %d, pri = %d, sz = %d\n", t->val, t->pri, t->size);
    if (t->l) {
        indent(ind);
        puts("l =");
        indent(ind);
        puts("{");
        print(t->l, ind + 1);
        indent(ind);
        puts("}");
    }
    if (t->r) {
        indent(ind);
        puts("r =");
        indent(ind);
        puts("{");
        print(t->r, ind + 1);
        indent(ind);
        puts("}");
    }
}
#endif

#ifdef PLR
void printlr(Treap* t) {
    printf("Size(t->l) = %d\n", Size(t->l));
    printf("Size(t->r) = %d\n", Size(t->r));
    puts("");
}
#endif

int main()
{
    srand(time(NULL));
    int n, m;
    int a, b;
    Treap *root;
    Treap *tl, *tm, *tr;
    scanf("%d%d", &n, &m);
    root = build(n);
#ifdef PT
    print(root, 0);
    return 0;
#endif
    while (m--) {
        scanf("%d%d", &a, &b);
        split(root, a-1, tl, tr);
        split(tr, b-a+1, tm, tr);
        reverse(tm);
        root = merge(merge(tl, tr), tm);
#ifdef PLR
        printlr(root);
#endif
    }
    for (int i = 1; i <= n; i++) {
        split(root, 1, tl, root);
        printf("%d\n", tl->val);
        delete tl;
    }
}
