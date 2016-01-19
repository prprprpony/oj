#include <bits/stdc++.h>
#define MAXN 25
using namespace std;
int n;
int r[MAXN];
int s[MAXN];
int x;
vector<int> tail;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];

    while (cin >> x) {
        s[x] = r[1];
        for (int i = 2; i <= n; i++) {
            cin >> x;
            s[x] = r[i];
        }

        tail.clear();
        tail.push_back(s[1]);
        for (int i = 2; i <= n; i++) {
                if (s[i] > tail.back())
                    tail.push_back(s[i]);
                else 
                    *upper_bound(tail.begin(), tail.end(), s[i]) = s[i];
        }
        cout << tail.size() << '\n';
    }

    return 0;
}
