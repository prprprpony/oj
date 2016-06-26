#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> id;
string name[1000];
int s[1000];
vector< vector< pair<int, int> > > h(1000);

int main()
{
    string p;
    int g;
    int M = 0;
    int t = -1;
    int w;

    cin >> n;
    while (n--) {
        cin >> p >> g;
        if (!id.count(p)) {
            id[p] = id.size() - 1;
            name[id[p]] = p;
        }
        int i = id[p];
        s[i] += g;
        h[i].push_back(pair<int, int>(s[i], n));
    }
    
    for (int i = 0; i < id.size(); i++)
        M = max(M, s[i]);

    for (int i = 0; i < id.size(); i++) {
        if (s[i] == M) {
            for (int j = 0; j < h[i].size() && h[i][j].second > t; j++)
                if (h[i][j].first >= M) {
                    w = i;
                    t = h[i][j].second;
                }
        }
    }

    cout << name[w] << endl;

    return 0;
}
