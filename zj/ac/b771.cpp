#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;

class Treap // of a sequence
{
    struct Node
    {
        char c;
        int sz;
        int p;
        Node *l, *r;
        Node(char k = 42) : c(k), sz(1), p(rand()), l(NULL), r(NULL) {}
    };

    static Node* gc;

    void delNode(Node* c) {
        c->l = gc;
        gc = c;
    }

    Node* newNode(char c) {
        if (gc) {
            Node* t = gc;
            gc = gc->l;
            *t = Node(c);
            return t;
        } else {
            return new Node(c);
        }
    }

    int size(Node* c) {
        return c ? c->sz : 0;
    }

    void pull(Node* c) {
        if (c)
            c->sz = 1 + size(c->l) + size(c->r);
    }

    void split(Node* t, int k, Node*& a, Node*& b) {
        if (size(t) <= k) {
            a = t;
            b = NULL;
        } else if (k == 0) {
            a = NULL;
            b = t;
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

    Node* merge(Node* a, Node* b) {
        if (!a || !b)
            return a ? a : b;
        if (a->p > b->p) {
            a->r = merge(a->r, b);
            pull(a);
            return a;
        } else {
            b->l = merge(a, b->l);
            pull(b);
            return b;
        }
    }

    void toString(Node* t, string& s) {
        if (!t)
            return;
        toString(t->l, s);
        s.push_back(t->c);
        toString(t->r, s);
    }

    Node* root;

public:

    Treap() : root(NULL) {}

    int size() {
        return size(root);
    }

    void insert(int k, char c) { // insert c as the kth element
        Node *tl, *dr;
        split(root, k-1, tl, dr);
        root = merge(merge(tl, newNode(c)), dr);
    }

    void remove(int k) {
        Node *tl, *dr;
        split(root, k-1, tl, dr);
        split(dr, 1, root, dr);
        delNode(root);
        root = merge(tl, dr);
    }

    void push_back(char c) {
        root = merge(root, newNode(c));
    }

    void pop_back() {
        Node* t;
        split(root, size() - 1, root, t);
        delNode(t);
    }

    void push_front(char c) {
        root = merge(newNode(c), root);
    }

    void pop_front() {
        Node* t;
        split(root, 1, t, root);
        delNode(t);
    }

    void toString(string &s) {
        toString(root, s);
    }
};

Treap::Node* Treap::gc = NULL;

int main()
{
    srand(42);
    char cmd[10];
    char pos[20];
    Treap s;
    while (scanf("%s %s", cmd, pos) == 2) {
        int k = 0;
        if (isdigit(pos[0]))
            sscanf(pos, "%d", &k);
        if (cmd[0] == 'i') {
            char c;
            scanf(" %c ", &c);
            if (pos[0] == 'l')
                s.push_front(c);
            else if (pos[0] == 'r')
                s.push_back(c);
            else
                s.insert(k, c);
        } else {
            if (pos[0] == 'l')
                s.pop_front();
            else if (pos[0] == 'r')
                s.pop_back();
            else
                s.remove(k);
        }
    }

    string seq;
    s.toString(seq);
//cout << seq << endl;
    int len = 0;
    if (seq.size()) {
        vc ans;
        len = 1;
        ans.push_back(seq[0]);
        for (int i = 1, cnt = 1; i < seq.size(); i++) {
            if (seq[i] == seq[i-1])
                cnt++;
            else
                cnt = 1;
            if (cnt > len) {
                ans.clear();
                len = cnt;
            }
            if (cnt == len)
                ans.push_back(seq[i]);
        }
        for (char c : ans)
            printf("%c ", c);
    }
    printf("%d\n", len);

    return 0;
}
