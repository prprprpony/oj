#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define X first
#define Y second
const int N = 1024, K = 31;
string solve_odd(int x,int y,int p=K-1)
{
    if (p == -1)
        return "";
    if (x < 0) {
        auto ret = solve_odd(-x,y,p);
        for (auto & c : ret)
            if (c == 'R')
                c = 'L';
            else if (c == 'L')
                c = 'R';
        return ret;
    }
    if (y < 0) {
        auto ret = solve_odd(x,-y,p);
        for (auto & c : ret)
            if (c == 'U')
                c = 'D';
            else if (c == 'D')
                c = 'U';
        return ret;
    }
    int v = 1<<p;
    if (x + y >= v) {
        if (x > y)
            return solve_odd(x-v,y,p-1) + "R";
        else
            return solve_odd(x,y-v,p-1) + "U";
    } else {
        auto ret = solve_odd(x,y,p-1);
        auto & c = ret.back();
        switch (c) {
        case 'L':
            c = 'R';
            return ret + 'L';
        case 'R':
            c = 'L';
            return ret + 'R';
        case 'U':
            c = 'D';
            return ret + 'U';
        case 'D':
            c = 'U';
            return ret + 'D';
        }
    }
}
pii p[N];
int main()
{
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].X >> p[i].Y;
        s += abs(p[i].X+p[i].Y)%2;
    }
    if (s == n) {
        cout << K << endl;
        for (int i = 0; i < K; ++i)
            cout << (1<<i) << " \n"[i==K-1];
        for (int i = 0; i < n; ++i)
            cout << solve_odd(p[i].X,p[i].Y) << endl;
    } else if (!s) {
        cout << K+1 << endl;
        for (int i = 0; i < K; ++i)
            cout << (1<<i) << " ";
        cout << "1\n";
        for (int i = 0; i < n; ++i)
            cout << solve_odd(p[i].X-1,p[i].Y) + "R" << endl;
    } else {
        cout << "-1\n";
    }
}
