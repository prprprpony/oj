#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct Node
{
    int val;
    struct Node* pre;
    struct Node* nxt;
};

void link(struct Node* a, struct Node* b)
{
    if (a != NULL)
        a->nxt = b;
    if (b != NULL)
        b->pre = a;
}

bool dfs(const int d, struct Node* start, const int h, const int maxd)
{
    if (h == 0)
        return true;
    if (3 * (maxd-d) < h)
        return false;
    if (d == maxd)
        return false;

    struct Node *i, *j, *k;
    int dh;
    for (i = start; i->nxt != NULL; i = i->nxt) {
        for (j = i; j->nxt != NULL; j = j->nxt) {
            struct Node *ip = i->pre, *jn = j->nxt;
/*
       NULL <- [start]...[ip] <-> [i]...[j] <-> [k=jn] <-> [k1]...[e] -> NULL
    => NULL <- [start]...[ip] <-> [jn] <-> [i]...[j] <-> [k=k1]...[e] -> NULL
                                .
                                .
                                .
    => NULL <- [start]...[ip] <-> [jn]...[e] <-> [i]...[j] -> NULL
*/
            for (k = j->nxt; k != NULL; k = j->nxt) {
                dh = 0;
                if (i->pre != NULL && i->pre->val + 1 == i->val)
                    ++dh;
                if (j->val + 1 == k->val)
                    ++dh;
                if (k->nxt != NULL && k->val + 1 == k->nxt->val)
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
    int n;
    int i;
    int h;
    int maxd;
    struct Node start;
    struct Node* it;
    start.pre = NULL;
    int case_num = 1;
    while (scanf("%d", &n) != EOF && n > 1) {
        scanf("%d", &start.val);
        for (i = 1, h = 0, it = &start; i <= n - 1; ++i) {
            it->nxt = (struct Node*)malloc(sizeof(struct Node));
            it->nxt->pre = it;
            it = it->nxt;
            scanf("%d", &(it->val));
            if (it->val != it->pre->val + 1)
                ++h;
        }
        it->nxt = NULL;

        for (maxd = 0; maxd < n; ++maxd)
            if (dfs(0, &start, h, maxd))
                break;

        printf("Case %d: %d\n", case_num++, maxd);

        struct Node* tmp;
        it = start.nxt;
        while (it != NULL) {
            tmp = it->nxt;
            free(it);
            it = tmp;
        }
    }
    return 0;
}
