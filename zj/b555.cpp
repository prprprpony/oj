#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1024;
int N, M;
int node[MAXN * MAXN * 4];
int ans[MAXN * MAXN];
int qr1, qr2, qc1, qc2;
int size;

void query(int t, int r1, int r2, int c1, int c2)
{
    if (r1 > r2 || c1 > c2 
        || r1 > qr2 || r2 < qr1 || c1 > qc2 || c2 < qc1
        || node[t] == (r2 - r1 + 1) * (c2 - c1 + 1))
        return;
    if (r1 == r2 && c1 == c2) {
        node[t] = 1;
        ans[size++] = r1 * (M + 1) + c1;
        return; 
    }
    int rm = (r1 + r2) / 2;
    int cm = (c1 + c2) / 2;
    query(4 * t + 1, r1, rm, c1, cm);
    query(4 * t + 2, r1, rm, cm + 1, c2);
    query(4 * t + 3, rm + 1, r2, c1, cm);
    query(4 * t + 4, rm + 1, r2, cm + 1, c2);
    node[t] = 0;
    for (int i = 1; i <= 4; ++i)
        node[t] += node[4 * t + i];
}

int main()
{
    int Q;
    scanf("%d%d%d", &N, &M, &Q);
    while (Q--) {
        scanf("%d%d%d%d", &qr1, &qc1, &qr2, &qc2);
        size = 0;
        query(0, 1, N, 1, M);
        printf("%d", size);
        sort(ans, ans + size);
        for (int i = 0; i < size; ++i)
            printf(" (%d, %d)", ans[i] / (M + 1), ans[i] % (M + 1));
        putchar('\n');
    }
}
