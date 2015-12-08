#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
vector<string> Name;
map<string, int> ID;
const int maxn = 30;
bool g[maxn][maxn];
int s[maxn];
vector<int> S[maxn];
int getID(const string &a)
{
    if (ID.count(a)) {
        return ID[a];
    } else {
        Name.push_back(a);
        return ID[a] = Name.size() - 1;
    }
}
int find(int x)
{
    return s[x] != x ? s[x] = find(s[x]) : x;
}
int main(void)
{
    int n, m, kase = 0;
    string a, b;
    while (cin >> n >> m && n) {
        Name.clear();
        ID.clear();
        memset(g, 0, sizeof(g));
        for (int i = 0; i < n; i++) {
            s[i] = i;
            S[i].clear();
        }
        while (m--) {
            cin >> a >> b;
            g[getID(a)][getID(b)] = true;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (g[i][j] && g[j][i])
                    s[find(i)] = find(j);
        for (int i = 0; i < n; i++)
            S[find(i)].push_back(i);
        if (kase)
            cout << '\n';
        cout << "Calling circles for data set " << ++kase << ":\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < S[i].size(); j++)
                cout << Name[S[i][j]] << (j < S[i].size() - 1 ? ", " : "\n");
    }
    return 0;
}
