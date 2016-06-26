#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e5 + 426;
pii s[maxn];

int main(void)
{
    int L, P, N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &s[i].X, &s[i].Y);
    scanf("%d%d", &L, &P);
    L -= P;
    sort(s, s + N);
    int ans = 0;
    int i = N - 1;
    priority_queue<int> pq;
    while (L > 0) {
        for ( ; i >= 0 && s[i].X >= L; i--)
            pq.push(s[i].Y);
        if (pq.empty())
            break;
        L -= pq.top();
        ++ans;
        pq.pop();
    }
    printf("%d\n", L <= 0 ? ans : -1);

    return 0;
}
