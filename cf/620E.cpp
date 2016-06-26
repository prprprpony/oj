#include <bits/stdc++.h>
#define MAXN (int)(4e5 + 42)
#define PB(a, b) a.push_back(b)
#define L first
#define R second
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int c[MAXN];
vi e[MAXN];
pii r[MAXN];
int i2c[MAXN];

struct Node
{
    ll color;
    ll settag;
    Node *lc, *rc;

    ll Color() {return settag ? settag : color;}

    void pull() {
        color = 0;
        if (lc)
            color |= lc->Color();
        if (rc)
            color |= rc->Color();
    }

    Node(int L, int R) : settag(0) {
        if (L == R) {
            color = 1LL << (i2c[L]);
            lc = rc = NULL;
        } else {
            int M = (L + R) / 2;
            lc = new Node(L, M);
            rc = new Node(M + 1, R);
            pull();
        }
    }

    void push() {
        if (settag) {
            color = settag;
            if (lc)
                lc->settag = settag;
            if (rc)
                rc->settag = settag;
            settag = 0;
        }
    }

    void set(int L, int R, int i, int j, ll t) {
        if (L > j || R < i)
            return;
        if (i <= L && R <= j) {
            settag = t;
            return;
        }
        push();
        int M = (L + R) / 2;
        lc->set(L, M, i, j, t);
        rc->set(M + 1, R, i, j, t);
        pull();
    }

    ll query(int L, int R, int i , int j) {
        if (L > j || R < i)
            return 0;
        if (i <= L && R <= j)
            return Color();
        push();
        int M = (L + R) / 2;
        return lc->query(L, M, i, j) | rc->query(M+1, R, i, j);
    }
};

int dfs(int p, int x, int s) {
    i2c[s] = c[x];
    int i = s;
    for (int c : e[x])
        if (c != p)
            i = dfs(x, c, i + 1);
    r[x] = {s, i};
    return i;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", c + i);
    for (int i = 0, x, y; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        PB(e[x], y);
        PB(e[y], x);
    }

    dfs(-1, 1, 0);
    Node* root = new Node(0, n - 1);

    for (int t, v, k; m > 0; m--) {
        scanf("%d", &t);
        switch (t) {
        case 1:
            scanf("%d%d", &v, &k);
            root->set(0, n-1, r[v].L, r[v].R, (1LL << k));
            break;
        case 2:
            scanf("%d", &v);
            ll a = root->query(0, n-1, r[v].L, r[v].R);
            k = 0;
            for (int i = 1; i <= 60; i++)
                if ((1LL << i) & a)
                    k++;
            printf("%d\n", k);
            break;
        }
    }

    return 0;
}
