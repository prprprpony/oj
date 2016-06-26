#include <iostream>
#include <cstring>
using namespace std;
int deg[26];
string tree;

int dfs(int i)
{
    // if (i >= tree.size())
    //     return 0;
    int j;
    for (j = i + 1; tree[j] != tree[i]; ) {
        int l = dfs(j);
        deg[tree[i]-'A']++;
        deg[tree[j]-'A']++;
        j += l;
    }
    return j - i + 1;
}

int main()
{
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        cin >> tree;
        memset(deg, 0, sizeof(deg));
        dfs(0);
        cout << "Case " << kase << '\n';
        for (int i = 0; i < 26; i++)
            if (deg[i])
                cout << (char)('A' + i) << " = " << deg[i] << '\n';
    }
}
