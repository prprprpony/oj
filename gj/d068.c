#include <stdio.h>

int move;

void hanoi(int n, char src, char dest, char tmp)
{
    if (n == 1) {
        printf("ring %d : %c => %c\n", n, src, dest);
    } else if (n > 1) {
        hanoi(n - 1, src, tmp, dest);
        printf("ring %d : %c => %c\n", n, src, dest);
        hanoi(n - 1, tmp, dest, src);
    } else {
        return;
    }
    move++;
}

void hanoi_3colors(int n, char src)
{
    for ( ; n > 0; n -= 3) {
        if (src == 'A') {
            hanoi(n - 1, 'A', 'B', 'C');
            printf("ring %d : A => C\n", n);
            move++;
            hanoi(n - 3, 'B', 'C', 'A');
            printf("ring %d : B => A\n", n - 2);
            move++;
            src = 'C';
        } else if (src == 'C') {
            hanoi(n - 2, 'C', 'A','B');
            printf("ring %d : C => B\n", n - 1);
            move++;
            src = 'A';
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    move = 0;
    hanoi_3colors(n, 'A');
    printf("共需%d個移動\n", move);
    return 0;
}
