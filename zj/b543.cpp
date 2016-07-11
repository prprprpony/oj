#include <iostream>
#include <algorithm>
using namespace std;
struct tiii
{
    int a[3];
    tiii() {}
    tiii(int x, int y, int z) : a{x, y, z} {}
    bool operator < (const tiii & r) const
    {
        if (a[0] != r.a[0])
            return a[0] < r.a[0];
        if (a[2] != r.a[2])
            return a[2] > r.a[2];
        if (a[1] != r.a[1])
            return a[1] < r.a[1];
        return false;
    }
} employee[5228];
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, s;
        cin >> N;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> employee[i].a[j];
        cin >> s;
        tiii x = employee[s - 1];
        sort(employee, employee + N);
        int ans = 1;
        for (int i = upper_bound(employee, employee + N, tiii(x.a[0]-1, 0x7fffffff, 0)) - employee - 1; i >= 0; ) {
            int tmpmax = 0;
            do {
                if (employee[i].a[2] < x.a[1]) {
                    ++ans;
                    tmpmax = max(tmpmax, employee[i].a[1]);
                }
                --i;
            } while(i >= 0 && employee[i].a[0] == employee[i+1].a[0]);
            x.a[1] = max(tmpmax, x.a[1]);
        }
        cout << ans << '\n';
    }
}

