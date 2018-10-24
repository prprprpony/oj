#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> s;
    while (n--) {
        int t,x,y;
        cin >> t >> x;
        if (t == 1) {
            s.insert(x);
        } else {
            cin >> y;
            for (auto it = s.lower_bound(x); it != end(s) && *it <= y; s.erase(it++));
        }
        if (s.empty()) {
            cout << "0\n";
        } else {
            x = *begin(s), y = *prev(end(s));
            if (x == y)
                cout << "1 " << x << '\n';
            else
                cout << "2 " << x << ' ' << y << '\n';
        }
    }
}
