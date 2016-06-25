#include <cstdio>
using namespace std;
int main()
{
    int N;
    while (scanf("%d", &N) == 1) {
        int S = 1;
        for (int i = 2; i * i <= N; ++i)
            if (!(N % i)) {
                S += i;
                if (N / i != i)
                    S += N / i;
            }
        puts(S > N ? "盈數" : S < N ? "虧數" : "完全數");
    }
}
