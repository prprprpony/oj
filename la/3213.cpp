#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[2][111];
int cnt[2][26];
int main()
{
    while (gets(s[0])) {
        gets(s[1]);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < 2; ++i)
            for (int j = 0; s[i][j] != '\0'; ++j)
                ++cnt[i][s[i][j] - 'A'];
        for (int i = 0; i < 2; ++i)
            sort(cnt[i], cnt[i] + 26);
        bool ok = true;
        for (int i = 0; i < 26 && ok; ++i)
            ok = cnt[0][i] == cnt[1][i];
        puts(ok ? "YES" : "NO");
    }
}
