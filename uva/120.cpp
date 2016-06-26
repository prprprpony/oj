#include <cstdio>
#include <cctype>
#include <algorithm>
#define ID(i) pn - (i) + 1
using namespace std;

int pancakes[40];
int pn;
int maxp;
int i, j;
char buf[314];
char* ss;

void flip(int a)
{
    for (j = 1; j < a; j++, a--)
        swap(pancakes[j], pancakes[a]);
}

int main(void)
{
    while (fgets(buf, sizeof buf, stdin) != NULL) {
        pn = 1;
        for (ss = buf;;) {
            sscanf(ss, "%d", &pancakes[pn]);

            while (isdigit(*ss)) ss++;
            if (*ss == ' ') {
                ss++;
                pn++;
            } else break;
        }
#ifdef IOTEST
        for (i = 1; i <= pn; i++) {
            printf("%d ", pancakes[i]);
        }
        putchar('\n');
#endif
        fputs(buf, stdout);
        for (i = pn; i > 0; i--) {
            maxp = i;
            for (j = i; j > 0; j--)
                if (pancakes[maxp] < pancakes[j])
                    maxp = j;
            if (maxp != i) {
                if (maxp != 1) {
                    printf("%d ", ID(maxp));
                    flip(maxp);
                }
                printf("%d ", ID(i));
                flip(i);
            }
        }
        printf("0\n");
    }
    return 0;
}
