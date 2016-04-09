#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 228;

struct Node
{
    int key;
    Node* pr; // this == leftest child ? parent : previous sibiling
    Node* lc; // left-child
    Node* rs; // right-sibiling
    Node() {}
    Node(int v) : key(v), pr(NULL), lc(NULL), rs(NULL) {}
};

Node mem[maxn];
Node* ptr;
Node* h[maxn];

inline void clear()
{
    ptr = mem;
}

inline void link_sb(Node* a, Node* b) // sibiling
{
    if (a)
        a->rs = b;
    if (b)
        b->pr = a;
}

inline void link_pc(Node* p,  Node* c) { // parent and child
    if (p)
        p->lc = c;
    if (c)
        c->pr = p;
}

inline Node* meld(Node* a, Node* b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->key < b->key)
        swap(a, b);
    link_sb(b, a->lc);
    link_pc(a, b);
    return a;
}

Node* remove_max(Node*& t)
{
    if (!t)
        return NULL;
    Node* tmp = t;
    Node* it = t->lc;
    t = NULL;
    if (!it)
        return tmp;

    Node* ret = NULL;
    Node* last = NULL;

    // first pass: left to right pairing
    while (it) {
        Node* a = it; // first child
        if (it = it->rs) { // second child
            it = it->rs; // third child, save it because meld wiil overwrite one of its arguments' rs
            a = meld(a, a->rs);
        }
        a->pr = last;
        last = a;
    }
    // second pass: right to left 
    for ( ; last; last = it) {
        it = last->pr; // because meld will overwrite one of its arguments' pr
        ret = meld(ret, last);
    }

    ret->pr = ret->rs = NULL;
    t = ret;

    return tmp;
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
            *h[i] = Node(k);
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
                    Node* tmp = remove_max(h[x[i]]);
                    *tmp = Node(tmp->key / 2);
                    h[x[i]] = meld(tmp, h[x[i]]);
                }
                h[x[0]] = meld(h[x[0]], h[x[1]]);
                p[x[1]] = x[0];
                printf("%d\n", h[x[0]]->key);
            } else {
                puts("-1");
            }
        }
    }
    return 0;
}
