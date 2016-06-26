#include <stdio.h>
int move;

void hanoi(int src, int p, int dest, int tmp)
{
    if (p == 1) {
        printf("ring %d : %c => %c\n", p, src, dest);
    } else if (p > 1){
        hanoi(src, p - 1, tmp, dest);
        printf("ring %d : %c => %c\n", p, src, dest);
        hanoi(tmp, p - 1, dest, src);
    } else {
        return;
    }
    move++;
}

void hanoi2colors(int plates, char src)
{
    for ( ; plates > 0; plates -= 2) {
        if (src == 'A') {
            hanoi('A', plates - 1, 'B', 'C');
            move++;
            printf("ring %d : A => C\n", plates);
            src = 'B';
        } else if (src == 'B') {
            hanoi('B', plates - 1, 'A', 'C');
            move++;
            printf("ring %d : B => C\n", plates);
            hanoi('A', plates - 2, 'C', 'B');
            printf("ring %d : A => B\n", plates - 1);
            move++;
            src = 'C';
        } else if (src == 'C') {
            hanoi('C', plates - 2, 'A', 'B');
            printf("ring %d : C => B\n", plates - 1);
            move++;
            src = 'A';
        }
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    move = 0;
    hanoi2colors(n, 'A');
    printf("共需%d個步驟\n", move);

    return 0;
}
