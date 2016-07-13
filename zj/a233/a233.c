#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000000

void swap(void * a, void * b, size_t size) {
    if (a == b)
        return;
    unsigned char c;
    while (size--) {
        c = *(unsigned char *)(a + size);
        *(unsigned char *)(a + size) = *(unsigned char *)(b + size);
        *(unsigned char *)(b + size) = c;
    }
}

void insertion_sort(void * first, size_t num, size_t size, int (*cmp)(const void *, const void *))
{
    void * i, * j;
    void * last = first + num * size;
    for (i = first + size; i < last; i += size)
        for (j = i; j > first && cmp(j, j - size) < 0; j -= size)
            swap(j - size, j, size);
}

int partition(void * first, size_t num, size_t size, int (*cmp)(const void *, const void *))
{
    size_t i;
    void * left, * right, * last;
    for (i = 0; i < 3; i++)
        swap(first + i * size, first + rand() % (num - i) * size, size);
    insertion_sort(first, 3, size, cmp);
    left = first + size;
    right = first + (num - 1) * size;
    last = right + size;
    swap(first, left, size);
    swap(left + size, right, size);
    while (1) {
        while (left < last && cmp(left, first) < 0)
            left += size;
        while (right > first && cmp(right, first) > 0)
            right -= size;
        if (left < right) {
            swap(left, right, size);
            left += size;
            right -= size;
        } else {
            break;
        }
    }
    swap(right, first, size);
    return (right - first) / size;
}

void q_sort(void * first, size_t num, size_t size, int (*cmp)(const void *, const void *))
{
    struct node {
        void * first;
        size_t length;
    };
    static struct node stack[32];
    int top = -1;
    int i;
    struct node cur;
#define SET(n, f, l) \
    do {\
        n.first = f;\
        n.length = l;\
    } while (0)
#define PUSH(f, l) \
    do {\
        top++;\
        SET(stack[top], f, l);\
    } while(0)
#define MI 4
    PUSH(first, num);
    while (top != -1) {
        cur = stack[top--];
#ifdef PP
int s = (int)((int*)cur.first - (int*)first);
printf("cur = [%d, %d]\n", s, s + (int)cur.length - 1);
#endif
        if (cur.length > MI) {
            i = partition(cur.first, cur.length, size, cmp);
#ifdef PP
printf("pivot = a[%d] = %d\n", s + i, *(int *)(cur.first + i * size));
#endif
            if (i > 1)
                PUSH(cur.first, i);
            if (cur.length - i - 1 > 1)
                PUSH(cur.first + (i + 1) * size, cur.length - i - 1);
            if (top > 0 && stack[top].length > stack[top - 1].length)
                swap(stack + top, stack + top - 1, sizeof(struct node));
        } else {
            insertion_sort(cur.first, cur.length, size, cmp);
#ifdef PP
puts("insertion_sort");
#endif
        }
#ifdef PP
for (int k = 0; k < cur.length; k++) {
    if (k && !(k%10))
        putchar('\n');
    printf("[%d:%d]%c", s + k, *(int *)(cur.first + k * size), k != cur.length - 1 ? ',' : '\n');
}
putchar('\n');
#endif
    }
}

int cmp(const void * a, const void * b)
{
    return *(int *)a > *(int *)b ? 1 : (*(int *)a < *(int *)b ? -1 : 0);
}

int main(void)
{
    int n;
    int i;
    int a[MAXN];

    srand(42);
    while (scanf("%d", &n) == 1 && 0 < n && n <= MAXN) {
        for (i = 0; i < n; i++)
            scanf("%d", a + i);
        q_sort(a, n, sizeof(int), cmp);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        putchar('\n');
    }
}

