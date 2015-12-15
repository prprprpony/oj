#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;
vector<int> d[26];
bool lit[26];
char buf[300];
int sep;
void dfs(int t, int m, int s)
{
    if (s == sep) {
        lit[t] = true;
        printf("%c ", t + 'A');
        s = 0;
    }
    for (vector<int>::iterator it = d[m].begin(); it != d[m].end(); it++)
        if (!lit[*it] && *it != t) {
            dfs(m, *it, s + 1);
            return;
        }
    printf("/%c\n", m + 'A');
}
int main()
{
    char *c, *k;
    char t, m;
    while (fgets(buf, sizeof(buf), stdin) != NULL && buf[0] != '#') {
        for (int i = 0; i < 26; i++)
            d[i].clear();
        memset(lit, 0, sizeof(lit));
        for (c = buf; ; c = k + 1) {
            for (k = c + 2; isalpha(*k); k++)
                d[*c - 'A'].push_back(*k - 'A');
            if (*k == '.')
                break;
        }
        sscanf(k + 1, " %c %c %d", &m, &t, &sep);
        dfs(t - 'A', m - 'A', 0);
    }
    return 0;
}
