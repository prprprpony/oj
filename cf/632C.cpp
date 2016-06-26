#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

bool cmp(int a, int b) {
    int sa = 0, sb = 0;
    while (1) {
        int i = sa, j = sb;
        for ( ; i < v[a].size() && j < v[b].size(); i++, j++)
            if (v[a][i] != v[b][j])
                return v[a][i] < v[b][j];
        if (i == v[a].size() && j == v[b].size())
            return false;
        else if (i == v[a].size())
            sb = j;
        else
            sa = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    v.resize(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p[i] = i;
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << v[p[i]];
    cout << '\n';

    return 0;
}

