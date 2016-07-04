#include <cstdio>
#include <random>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 1.3e5;
mt19937 rr(20101010);
struct Node
{
    unsigned int rev:1;
    unsigned int val:31;
    unsigned int pri;
    int sz;
    Node * c[2];
    Node() {}
    Node(int k) : rev(0), val(k), pri(rr()), sz(1), c{NULL, NULL} {}
};

Node mem[maxn];

inline void reverse(Node * t)
{
    if (t)
        t->rev ^= 1;
}

void push(Node * t) 
{
    if (t && t->rev) {
        swap(t->c[0], t->c[1]);
        reverse(t->c[0]);
        reverse(t->c[1]);
        t->rev = 0;
    }
}

inline int size(Node * t)
{
    return t ? t->sz : 0;
}

inline void pull(Node * t)
{
    if (t)
        t->sz = size(t->c[0]) + 1 + size(t->c[1]);
}

Node * meld(Node * a, Node * b)
{
    if (!a || !b)
        return a ? a : b;
    if (a->pri > b->pri) {
        push(a);
        a->c[1] = meld(a->c[1], b);
        pull(a);
        return a;
    } else {
        push(b);
        b->c[0] = meld(a, b->c[0]);
        pull(b);
        return b;
    }
}

void split(Node * t, int k, Node *& a, Node *& b) // a = t[1:k], b = t[k+1: ]
{
    if (!k) {
        a = NULL;
        b = t;
        return;
    }
    push(t);
    if (size(t->c[0]) + 1 <= k) {
        a = t;
        split(t->c[1], k - size(t->c[0]) - 1, a->c[1], b);
        pull(a);
    } else {
        b = t;
        split(t->c[0], k, a, b->c[0]);
        pull(b);
    }
}

Node * build(int N)
{
    Node * last;
    vector<Node *> rc;
    for (int i = 0; i < N; ++i) {
        mem[i] = Node(i + 1);
        last = NULL;
        while (rc.size() && rc.back()->pri < mem[i].pri) {
            rc.back()->c[1] = last;
            last = rc.back();
            pull(last);
            rc.pop_back();
        }
        mem[i].c[0] = last;
        rc.push_back(mem + i);
    }
    last = NULL;
    while (rc.size()) {
        rc.back()->c[1] = last;
        last = rc.back();
        pull(last);
        rc.pop_back();
    }
    return last;
}

Node * reverse(Node * t, int l, int r)
{
    Node * tl, * tr;
    split(t, l - 1, tl, t);
    split(t, r - l + 1, t, tr);
    reverse(t);
    return meld(meld(tl, t), tr);
}

void p(Node * t, int & n) 
{
    if (t) {
        push(t);
        p(t->c[0], n);
        printf("%d%c", t->val, --n ? ' ' : '\n');
        p(t->c[1], n);
    }
}

inline void print(Node * t, int n)
{
    p(t, n);
}

int main()
{
    int N, M;
    while (scanf("%d%d", &N, &M) == 2) {
        Node * treap = build(N);
        while (M--) {
            int p, q;
            scanf("%d%d", &p, &q);
            treap = reverse(treap, p, q);
        }
        print(treap, N);
    }
}
