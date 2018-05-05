#include <bits/stdc++.h>
using namespace std;
const int N = 3e4;
int a[N], b[N];
void Init()
{
    unsigned int seed = time(0) / 60;
    srand(seed);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Init();
    iota(a,a+N,0);
    for (int i = 0; i < N; ++i)
        swap(a[i], a[i + rand() % (N - i)]);
    for (int i = 0; i < N; ++i)
        b[a[i]] = i;
    cout << N << '\n';
    for (int i = 0; i < N; ++i)
        cout << b[i] << " \n"[i+1==N];
}
