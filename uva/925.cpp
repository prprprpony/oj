#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 128;
string name[maxn];
map<string, int> id;
vector<int> pre[maxn];
int cand[maxn];

int main()
{
    int C;
    cin >> C;
    while (C--) {
        int k;
        cin >> k;
        id.clear();
        for (int i = 0; i < k; ++i)
            cin >> name[i];
        sort(name, name + k);
        for (int i = 0; i < k; ++i) {
            pre[i].clear();
            id[name[i]] = i;
        }
        int j;
        cin >> j;
        for (int i = 0; i < j; ++i) {
            string c;
            int p;
            cin >> c >> p;
            cand[i] = id[c];
            while (p--) {
                string pc;
                cin >> pc;
                pre[cand[i]].push_back(id[pc]);
            }
            sort(pre[cand[i]].begin(), pre[cand[i]].end());
        }
        sort(cand, cand + j);

        for (int i = 0; i < j; ++i) {
            vector<bool> isp(k), vis(k);
            queue<int> q;
            int num = pre[cand[i]].size();
            for (int p : pre[cand[i]]) {
                isp[p] = true;
                vis[p] = true;
                q.push(p);
            }
            while (!q.empty() && num > 1) {
                for (int p : pre[q.front()]) {
                    if (!vis[p]) {
                        vis[p] = true;
                        q.push(p);
                    } else if (isp[p]) {
                        isp[p] = false;
                        --num;
                    }
                }
                q.pop();
            }
            cout << name[cand[i]] << ' ' << num;
            for (int p : pre[cand[i]])
                if (isp[p])
                    cout << ' ' << name[p];
            cout << '\n';
        }
    }
    return 0;
}
