#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+87, K = 26;
const int LOGN = __lg(N)+1;
string a[N];
struct node
{
    int nxt[K],leaf,go[K],fail;
    node()
    {
        memset(nxt,-1,sizeof nxt);
        memset(go,-1,sizeof nxt);
        fail = -1;
        leaf = 0;
    }
} t[N];
int ptr;
vector<int> gc;
int newnode()
{
    if (gc.size()) {
        int p = gc.back();
        gc.pop_back();
        t[p] = node();
        return p;
    }
    return ptr++;
}
struct AC
{
    int rt;
    vector<int> idx;
    void dump(vector<int> & v) 
    {
        for (int i : idx)
            v.push_back(i);
        clear();
    }
    int size()
    {
        return idx.size();
    }
    void clear()
    {
        idx.clear();
        dfs_clear(rt);
        rt = -1;
    }
    void dfs_clear(int u)
    {
        gc.push_back(u);
        for (int j = 0; j < K; ++j)
            if (t[u].nxt[j] != -1)
                dfs_clear(t[u].nxt[j]);
    }
    void bld()
    {
        rt = newnode();
        for (int i : idx) {
            int o = rt;
            for (char ch : a[i]) {
                int c = ch - 'a';
                int & p = t[o].nxt[c];
                if (p == -1)
                    p = newnode();
                o = p;
            }
            t[o].leaf++;
        }
        queue<int> q;
        t[rt].fail = rt;
        for (int j = 0; j < K; ++j) {
            int p = t[rt].nxt[j];
            t[rt].go[j] = p == -1 ? rt : p;
            if (p != -1) {
                t[p].fail = rt;
                q.push(p);
            }
        }
        while (q.size()) {
            int o = q.front();
            q.pop();
            t[o].leaf += t[t[o].fail].leaf;
            for (int j = 0; j < K; ++j) {
                int p = t[o].nxt[j];
                if (p != -1) {
                    t[o].go[j] = p;
                    q.push(p);
                    t[p].fail = t[t[o].fail].go[j];
                } else {
                    t[o].go[j] = t[t[o].fail].go[j];
                }
            }
        }
    }
    void prt(int u)
    {
        cerr << "=============\n";
        cerr << u << endl;
        cerr << "go ";
        for (int j = 0; j < K; ++j)
            cerr << t[u].go[j] << ' ';
        cerr << endl << "fail " << t[u].fail << endl;
        for (int j = 0; j < K; ++j)
            if (t[u].nxt[j] != -1)
                prt(t[u].nxt[j]);
    }
    ll cnt(int i)
    {
        if (size() == 0)
            return 0;
        assert(rt != -1);
        ll ret = 0;
        int o = rt;
        for (char ch : a[i]) {
            o = t[o].go[ch-'a'];
            ret += t[o].leaf;
            /*
            cerr << "=============\n";
            cerr << ch << endl;
            cerr << o << endl;
            cerr << t[o].dp << endl;
            */
        }
        return ret;
    }
};
struct DC
{
    AC b[LOGN];
    void ins(int i)
    {
        vector<int> now{i};
        for (int j = 0; j < LOGN; ++j)
            if (b[j].size()) {
                b[j].dump(now);
            } else {
                swap(b[j].idx, now);
                b[j].bld();
                break;
            }
    }
    ll cnt(int i)
    {
        ll ret = 0;
        for (int j = 0; j < LOGN; ++j)
            ret += b[j].cnt(i);
        return ret;
    }
} all, del;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int tt;
        cin >> tt >> a[i];
        if (tt == 1)
            all.ins(i);
        else if (tt == 2)
            del.ins(i);
        else
            cout << all.cnt(i) - del.cnt(i) << endl;
    }
}
