#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<string> ok;
vector<vector<bool> > vis(3,{0,0,0});
int pos(int i, int j)
{
    return i * 9 + j;
}
void putsqr(string & s, int r, int c)
{
    c <<= 1;
    s[pos(r, c + 1)] = s[pos(r, c + 3)] = s[pos(r + 2, c + 1)] = s[pos(r + 2, c + 3)] = '_';
    s[pos(r + 1, c)] = s[pos(r + 1, c + 4)] = s[pos(r + 2, c)] = s[pos(r + 2, c + 4)] = '|';
    s[pos(r + 1, c + 1)] = s[pos(r + 1, c + 2)] = s[pos(r + 1, c + 3)] = s[pos(r + 2, c + 2)] = ' ';
}
void printsqr(const string & s)
{
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 9; ++c)
            cout << s[pos(r, c)];
        cout << "#\n";
    }
    cout << '\n';
}
void build(string & s, int d, int e)
{
    if (ok.count(s))
        return;
    if (d)
        ok.insert(s);
#ifdef PP
    if (d <= 2)
        printsqr(s);
#endif
    if (d == e)
        return;
    string t(s);
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            if (!vis[r][c]) {
                vis[r][c] = true;
                putsqr(s, r, c);
                build(s, d + 1, e);
                s = t;
                vis[r][c] = false;
            }
}
int main()
{
    ios_base::sync_with_stdio(false);
    string s(45, ' ');
    build(s, 0, 6);

    while (getline(cin, s) && s[0] != '0') {
        s.pop_back();
        for (int i = 0; i < 4; ++i) {
            string t;
            getline(cin, t);
            t.pop_back();
            s += t;
        }
        static int kase = 0;
        cout << "Case " << ++kase << ": " << (ok.count(s) ? "Yes" : "No") << '\n';
    }
}
