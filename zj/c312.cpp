#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
int f[N];
void add(int i, int v)
{
    for (; i < N; i += i & -i)
        f[i] += v;
}
int qry(int i)
{
    int r = 0;
    for (; i > 0; i -= i & -i)
        r += f[i];
    return r;
}
int bins(int v)
{
    int i = 0, u = 0;
    for (int k = 1 << __lg(N); k; k >>= 1) 
        if (i + k < N && u + f[i + k] < v) {
            i += k;
            u += f[i];
        }
    return i + 1;
}
int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        fill_n(f, n + 1, 0);
        for (int i = 1; i <= n; ++i)
            add(i, 1);
        int cur = 1;
        for (int w = n; w > 1; --w) {
            int kill = (cur + k - 1) % w;
            if (kill == 0)
                kill = w;
            int i = bins(kill);
            add(i, - 1);
            cur = qry(i) + 1;
        }
        printf("%d\n", bins(1));
    }
}
