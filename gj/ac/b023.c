#include <stdio.h>
void hona(int src, int p, int dest, int tmp)
{
    if (p == 1) {
        printf("Ring 1 from %d to %d\n", src, dest);
    } else {
        hona(src, p - 1, tmp, dest);
        printf("Ring %d from %d to %d\n", p, src, dest);
        hona(tmp, p - 1, dest, src);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hona(1, n, 3, 2);

    return 0;
}
