#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
    int x[2];
};

int g_i;
bool cmp(const Node *a, const Node *b)
{
    return a->x[g_i] > b->x[g_i];
}

int sqr(int x)
{
    return x * x;
}

Node node[60];
Node *no[60];

int main()
{
    int n;
    int dsqr;
    scanf("%d", &n);

    for (int t = 0; t < 2; t++)
        for (int i = 0; i < n; i++)
            scanf("%d", &node[i].x[t]);
    for (int i = 0; i < n; i++)
        no[i] = &node[i];
    
    for (int t = 0; t < 2; t++) {
        g_i = t;
        sort(no, no+n, cmp);
        for (int i = 0; i < n; i++)
            no[i]->x[t] = i+1;
    }

    dsqr = 0;
    for (int i = 0; i < n; i++)
        dsqr += sqr(node[i].x[0] - node[i].x[1]);
    
    printf("%+.3f\n", 1.0 - 6.0 * dsqr / (n * (sqr(n) - 1)));

    return 0;
}
