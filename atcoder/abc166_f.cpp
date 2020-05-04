#include<bits/stdc++.h>
using namespace std;
string ans = "Yes\n";
void p(int & a, int & b, char A, char B)
{
    if (a == 0 && b == 0) {
        cout << "No\n";
        exit(0);
    }
    if (a > b) {
        --a;
        ++b;
        ans += B;
    } else {
        --b;
        ++a;
        ans += A;
    }
    ans += '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> vs(n);
    for (auto & s : vs)
        cin >> s;
    for (int i = 0; i < n; ++i) {
        string s = vs[i];
        if (s == "AB") {
            if (a == 1 && b == 1 && c == 0 && i + 1 < n && vs[i + 1] == "BC") {
                p(b, a, 'B', 'A');
            } else {
                p(a, b, 'A', 'B');
            }
        } else if (s == "AC") {
            if (a == 1 && c == 1 && b == 0 && i + 1 < n && vs[i + 1] == "BC") {
                p(c, a, 'C', 'A');
            } else {
                p(a, c, 'A', 'C');
            }
        } else if (s == "BC") {
            if (b == 1 && c == 1 && a == 0 && i + 1 < n && vs[i + 1] == "AC") {
                p(c, b, 'C', 'B'); 
            } else {
                p(b, c, 'B', 'C'); 
            }
        }
    }
    cout << ans;
}

