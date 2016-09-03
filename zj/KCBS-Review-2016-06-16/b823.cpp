#include <cstdio>
int main(void)
{
    int v;
    int N = 0, B = 0, S = 0, A = 0;
    while (scanf("%d", &v) == 1) {
        ++N;
        if (v > 0) {
            B += v;
            ++A;
        }
        if (v == -1)
            ++S;
    }
    printf("%.2f %.2f %.2f\n", N == S ? 0.0 : (1.0 * A / (N - S)), 1.0 * (A + S) / N, N == S ? 0.0 : (1.0 * B / (N - S)));
    return 0;
}
