#include <bits/stdc++.h>
using namespace std;
const int N = 1<<10;
int n,m,k;
deque<int> q[N][2]; // ><
int a[N][N];
int main()
{
    int ans = 1e9;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m ; ++j)
            scanf("%d",a[i]+j);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            deque<int> & q0 = q[i][0];
            deque<int> & q1 = q[i][1];
            while (q0.size() && a[i][j] >= a[i][q0.back()])
                q0.pop_back();
            q0.push_back(j);
            if (q0.front() == j - k)
                q0.pop_front();
            while (q1.size() && a[i][j] <= a[i][q1.back()])
                q1.pop_back();
            q1.push_back(j);
            if (q1.front() == j - k)
                q1.pop_front();
        }
        if (j < k-1) continue;
        deque<int> q0,q1;
        for (int i = 0; i < n; ++i) {
            while (q0.size()) {
                int x = q0.back();
                if (a[i][q[i][0].front()] >= a[x][q[x][0].front()])
                    q0.pop_back();
                else
                    break;
            }
            q0.push_back(i);
            if (q0.front() == i - k)
                q0.pop_front();
            while (q1.size()) {
                int x = q1.back();
                if (a[i][q[i][1].front()] <= a[x][q[x][1].front()])
                    q1.pop_back();
                else
                    break;
            }
            q1.push_back(i);
            if (q1.front() == i - k)
                q1.pop_front();
            if (i >= k - 1) {
                int x = q0.front(), y = q1.front();
                ans = min(ans, a[x][q[x][0].front()] - a[y][q[y][1].front()]);
            }
        }
    }
    printf("%d\n",ans);
}
