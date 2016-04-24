#include <cstdio>
using namespace std;

int nxt[9];
char out[9];

void full_permutation(int p)
{
    if (!nxt[0]) {
        puts(out);
        return;
    }
    for (int i = 0; nxt[i]; i = nxt[i]) {
        int c = nxt[i];
        out[p] = c + '0';
        nxt[i] = nxt[c]; // erase c from the list
        full_permutation(p + 1);
        nxt[c] = nxt[i]; // insert c in its original position in the list
        nxt[i] = c;
    }
}

int main(void)
{
    int n;
    while (scanf("%d", &n) == 1) {
        nxt[0] = n;
        for (int i = n; i > 0; --i)
            nxt[i] = i - 1;
        out[n] = '\0';
        full_permutation(0);
    }
    return 0;
}
