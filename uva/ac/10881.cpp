#include <cstdio>
#include <cstring>
#include <algorithm>
#define P first
#define D second
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e4 + 228;
pii ants[2][maxn];
int id[maxn];
int rk[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    for (int kase = 1; kase <= N; ++kase) {
        int L, T, n;
        scanf("%d%d%d", &L, &T, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d ", &ants[0][i].P);
            ants[0][i].D = getchar() == 'R' ? 1 : -1;
            ants[1][i] = ants[0][i];
            ants[1][i].P += T * ants[0][i].D;
            id[i] = i;
        }
        sort(id, id + n, [=] (int a, int b) -> bool {return ants[0][a] < ants[0][b];});
        sort(ants[1], ants[1] + n);
        for (int i = 0; i < n; ++i)
            rk[id[i]] = i;
        vector<bool> turning(n);
        for (int i = 0; i < n - 1; ++i)
            if (ants[1][i].P == ants[1][i+1].P)
                turning[id[i]] = turning[id[i+1]] = true;

        printf("Case #%d:\n", kase);
        for (int i = 0; i < n; ++i) {
            const pii& a = ants[1][rk[i]];
            if (a.P < 0 || a.P > L)
                puts("Fell off");
            else {
                printf("%d ", a.P);
                puts(turning[i] ? "Turning" : (a.D > 0 ? "R" : "L"));
            }
        }
        puts("");
    }
    return 0;
}
