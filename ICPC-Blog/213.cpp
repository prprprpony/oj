#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 3e5 + 87;
const int S = sqrt(N);
vector<int> g[N], input[N];
vector<pii> qry[N];
int n,m,QAQ[N],in[N],vc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    int q;
    cin >> q;
    for (int kase = 0; kase < q; ++kase) {
        vector<int> & a = input[kase];
        int k;
        cin >> k;
        a.resize(k);
        QAQ[kase] = -k;
        for (int & x : a)
            cin >> x;
        if (k <= S) {
            sort(begin(a),end(a));
            for (int i = 0; i < k; ++i)
                qry[a[i]].emplace_back(kase,i+1);
        } else {
            ++vc;
            for (int i = 0; i < k; ++i)
                in[a[i]] = vc;
            for (int i = 0; i < k; ++i)
                for (int j : g[a[i]])
                    QAQ[kase] += in[j] == vc;
        }
    }
    for (int u = 0; u < n; ++u) {
        ++vc;
        for (int v : g[u])
            in[v] = vc;
        for (const auto & p : qry[u])
            for (int j = p.S; j < input[p.F].size(); ++j)
                QAQ[p.F] += in[input[p.F][j]] == vc;
    }
    for (int i = 0; i < q; ++i)
        cout << QAQ[i] << '\n';
}
