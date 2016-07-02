#include <stdio.h>
void swap(void * a, void * b, size_t size)
{
    char t;
    size_t i;
    for (i = 0; i < size; ++i) {
        t = ((char *)a)[i] ;
        ((char *)a)[i]  = ((char *)b)[i];
        ((char *)b)[i] = t;
    }
}

void gnome_sort(void * base, size_t num, size_t size, int (*cmp)(const void *, const void *)) 
{
    char * pos = (char *)base;
    char * last = (char *)base + num * size;
    while (pos != last)
        if (pos == base || cmp(pos - size, pos) <= 0)
            pos += size;
        else {
            swap(pos - size, pos, size);
            pos -= size;
        }
}

int compare(const void * a, const void * b) 
{
    return *(int *)a > *(int *)b ? 1 : *(int *)a < *(int *)b ? -1 : 0;
}

int main()
{
    int a[1000];
    int n;
    int i;
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; ++i)
            scanf("%d", a + i);
        gnome_sort(a, n, sizeof(int), compare);
        for (i = 0; i < n; ++i)
            printf("%d%c", a[i], i != n - 1 ? ' ' : '\n');
    }
}
