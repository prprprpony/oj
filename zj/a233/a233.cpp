#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e6;
const double ratio = 0.42;
const int threshold = 16;
int a[MAXN];
void insertion_sort(int * const first, int * const last)
{
    if (first == last)
        return;
    for (int * it = first + 1; it != last; ++it)
        for (int * r = it; r != first && *r < *(r - 1); --r)
            swap(*(r - 1), *r);
}
void flash_sort(int * const first, int * const last)
{
    const int M = ratio * (last - first);
    if (M <= 1 || last - first <= threshold) {
        insertion_sort(first, last);
        return;
    }
    int * L = new int[M]();
    long long maxv = *first, minv = *first;
    for (int * it = first + 1; it != last; ++it)
        if (*it > maxv)
            maxv = *it;
        else if (*it < minv)
            minv = *it;
    if (maxv == minv)
        return;
    auto k = [&] (int v) -> int {return 1.0 * (v - minv) / (maxv - minv) * (M - 1);};
    for (int *it = first; it != last; ++it)
        ++L[k(*it)];
    for (int i = 1; i < M; ++i)
        L[i] += L[i-1];
    for (int *it = first; it != last; ++it) {
        int i;
        while (L[i = k(*it)] > it - first) {
            if (--L[i] == it - first)
                break;
            swap(*it, *(first + L[i]));
        }
    }
    for (int i = 1; i < M; ++i)
        flash_sort(first + L[i - 1], first + L[i]);
    flash_sort(first + L[M - 1], last);
    delete[] L;
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) 
        scanf("%d", a + i);
    flash_sort(a, a + N);
    printf("%d", a[0]);
    for (int i = 1; i < N; ++i) 
        printf(" %d", a[i]);
    putchar('\n');
}
