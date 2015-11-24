#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAXNODE 362880

int n;
int maxd;
int state;

inline int pow10(int p)
{
    int r, i, d;
    for (r = 1, i = 1, d = 10; i <= p; i <<= 1, d *= d)
        if (i&p)
            r *= d;
    return r;
}

inline int getDigit(int i)
{
    return state / pow10(i) % 10;
}

inline int getRange(int i, int j)
{
    return state / pow10(i) % pow10(j-i+1);
}

bool dfs(const int d, int state, const int h)
{
    if (h == 0)
        return true;
    if (3 * (maxd-d) < h)
        return false;
    if (d == maxd)
        return false;

    int i, j, k;
    int dh;
    for (i = 0; i < n-1; ++i) {
        for (j = i; j < n-1; ++j) {
            int ip = i-1, jn = j+1;
/*
       NULL <- [start]...[ip] <-> [i]...[j] <-> [k=jn] <-> [k1]...[e] -> NULL
    => NULL <- [start]...[ip] <-> [jn] <-> [i]...[j] <-> [k=k1]...[e] -> NULL
                                .
                                .
                                .
    => NULL <- [start]...[ip] <-> [jn]...[e] <-> [i]...[j] -> NULL
*/
            for (k = j+1; k < n; k = j+1) {
                dh = 0;
                if (i-1 > -1 && getDigit(i-1) + 1 == getDigit(i))
                    ++dh;
                if (getDigit(j) + 1 == getDigit(k))
                    ++dh;
                if (k+1 < n && getDigit(k) + 1 == getDigit(k+1))
                    ++dh;

                link(j, k->nxt);
                link(i->pre, k);
                link(k, i);

                if (k->pre != NULL && k->pre->val + 1 == k->val)
                    --dh;
                if (k->val + 1 == i->val)
                    --dh;
                if (j->nxt != NULL && j->val + 1 == j->nxt->val)
                    --dh;

                if (dfs(d + 1, start, h + dh, maxd)) {
                    link(i->pre, j->nxt);
                    link(ip, i);
                    link(j, jn);
                    return true;
                }
            }
/*
        NULL <- [start]...[ip] <-> [jn]...[e] <-> [i]...[j] -> NULL
    =>  NULL <- [start]...[ip] <-> [i]...[j] <-> [jn]...[e] -> NULL
*/
            i->pre->nxt = NULL;
            link(ip, i);
            link(j, jn);
        }
    }
    return false;
}

int main()
{
    int i;
    int h;
    int p;
    int case_num = 1;
    while (scanf("%d", &n) != EOF && n > 1) {
        h = 0;
        scanf("%d", &state);
        for (i = 1; i < n; ++i) {
            scanf("%d", &p);
            if (p != (state%10)+1)
                ++h;
            state *= 10;
            state += p;
        }

        for (maxd = 0; maxd < n; ++maxd)
            if (dfs(0, state, h))
                break;

        printf("Case %d: %d\n", case_num++, maxd);
    }
    return 0;
}
