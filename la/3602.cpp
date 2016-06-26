#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
int cnt[1001][4];
char seq[1001];
const char dna[] = "ACGT";
int getid(char c)
{
    for (int i = 0; dna[i]; ++i)
        if (c == dna[i])
            return i;
    assert(0);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, n;
        scanf("%d%d ", &m, &n);
        memset(cnt, 0, n * 4 * sizeof(int));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                ++cnt[j][getid(getchar())];
            getchar();
        }
        int dist = 0;
        for (int i = 0; i < n; ++i) {
            int c = 0;
            for (int j = 1; j < 4; ++j)
                if (cnt[i][j] > cnt[i][c])
                    c = j;
            seq[i] = dna[c];
            dist += m - cnt[i][c];
        }
        seq[n] = '\0';
        printf("%s\n%d\n", seq, dist);
    }
    
    return 0;
}
