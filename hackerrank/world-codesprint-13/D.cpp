#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define F first
#define S second
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ls = 0, rs = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '(')
            ++ls;
        else {
            if (ls)
                --ls;
            else
                ++rs;
        }
    }
    if (ls && rs)
        cout << "2\n";
    else if (ls || rs)
        cout << "1\n";
    else
        cout << "0\n";
}
