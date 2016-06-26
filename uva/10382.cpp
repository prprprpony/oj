#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#define MAXN (int)(1e4 + 42)
#define X first
#define Y second
//#define EPS 1e-8
using namespace std;
typedef pair<double, double> pdd;
pdd seg[MAXN];
int top;

int main()
{
    int n, l, w;
    while (scanf("%d%d%d", &n, &l, &w) == 3) {
        top = 0;
        for (int i = 0; i < n; i++) {
            int p, r;
            scanf("%d%d", &p, &r);
            if (r * 2 > w) {
                double k = sqrt(pow(r, 2.0) - pow(w / 2.0, 2.0));
                seg[top++] = {max(0.0, p - k), min(l + 0.0, p + k)};
            }
        }
        sort(seg, seg + top);
#ifdef PP
for (int i = 0; i < top; i++)
    printf("SEG%02d: [%f, %f]\n", i, seg[i].X, seg[i].Y);
#endif
        int ans = 0;
        double right = 0.0;
        int last = 0;
        while (last != top && right != l) {
            double nr = 0.0;
            for ( ; last < top && seg[last].X <= right; last++)
                nr = max(nr, seg[last].Y);
            if (nr == 0.0) {
                ans = -1;
                goto output;
            }
            ans++;
            right = nr;
        }
        if (right != l)
            ans = -1;
output:
        printf("%d\n", ans);
    }
    return 0;
}
