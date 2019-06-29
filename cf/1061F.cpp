#include<bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
map<tuple<int,int,int>,bool> qc;
int n,k;
bool q(int a,int b,int c)
{
    if (a > c)
        swap(a,c);
    if (a == b || b == c)
        return true;
    if (a == c)
        return false;
    auto t = make_tuple(a,b,c);
    if (qc.count(t) == 0) {
        assert(qc.size() < 60 * n);
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        string s;
        cin >> s;
        qc[t] = s == "Yes";
    }
    return qc[t];
}
vector<int> ts;
pair<int,int> lca(int u,int v)
{
    vector<int> p;
    int su = 1, sv = 1;
    for (int i = 1; i <= n; ++i) {
        if (i == u || i == v) 
            continue;
        if (q(i,u,v))
            ++su;
        else if (q(i,v,u))
            ++sv;
        else if (q(u,i,v))
            p.push_back(i);
    }
    if (su % k == 0)
        return {u, (n-su)*k+1};
    if (sv % k == 0)
        return {v,(n-sv)*k+1};
    sort(begin(p),end(p),[&](int i,int j){
        return q(u,i,j);
    });
    int du=-1,dv=-1;
    for (int i = 0; i < ts.size(); ++i) {
        if (ts[i] == su)
            du=i;
        if (ts[i] == sv)
            dv=i;
    }
    assert(du>=0&&dv>=0);
    int tl = 2+du+dv+p.size();
    int dw = (tl+1)/2-1;
    return {p[dw-du-1], ts[dw]};
}
int ra() {return gen()%n+1;}
int main()
{
    cin >> n >> k;
    ts = {1};
    while (ts.back() < n)
        ts.push_back(ts.back() * k + 1);
    int u = ra(), sz = 0;
    while (sz < n) {
        int v=ra();
        if (u == v)
            continue;
        tie(u,sz) = lca(u,v);
    }
    cout << "! " << u << endl;
}
