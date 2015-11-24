#include <stdio.h>
#include <string.h>
#define MAXW 60 
typedef long long LL;
LL d[MAXW][2];
LL dp(int w, int b)
{
    if (d[w][b])
        return d[w][b];
    return d[w][b] = (b ? dp(w-1,0) : dp(w-1,1) + dp(w-1,0));
}

int main()
{
    int n, i, w;
    memset(d, 0, sizeof(d));
    d[1][0] = d[1][1] = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &w);
        printf("Scenario #%d:\n", i);
        printf("%lld\n\n", dp(w, 0) + dp(w, 1));
    }
    
    return 0;
}
