#include<bits/stdc++.h>
using namespace std;
void go(vector<int> & x,int o)
{
    if (!o)
        return;
    assert(x.size());
    int b = x.back();
    x.pop_back();
    assert(o == 1 || x.size());
    switch (o) {
        case 1:
            x.push_back(b^1);
            break;
        case 2:
            x.back()&=b;
            break;
        case 3:
            x.back()|=b;
            break;
        case 4:
            x.back()=x.back()==b;
            break;
        case 5:
            x.back() = !x.back() || b;
            break;
        case 6:
            x.back() ^= b;
            break;
    }
}
bool eval(const string & s,int a)
{
    vector<int> op;
    vector<int> x;
    const int pri[] = {0,1,2,3,3,3,3};
    for (int i = 0; i < s.size(); ++i) {
        if (isalpha(s[i])) {
            x.push_back(a>>(s[i]-'a')&1);
            continue;
        }
        bool rt = 0;
        switch (s[i]) {
        case '(':
            op.push_back(0);
            break;
        case ')':
            rt = 1;
            break;
        case '!':
            op.push_back(1);
            break;
        case '&':
            op.push_back(2);
            break;
        case '|':
            ++i;
            op.push_back(3);
            break;
        case '<':
            i += 2;
            op.push_back(4);
            break;
        case '=':
            i += 1;
            op.push_back(5);
            break;
        case '#':
            op.push_back(6);
            break;
        }
        if (rt) {
            int t = -1;
            do {
                t = op.back();
                op.pop_back();
                go(x,t);
            } while (t != 0);
        } else {
            int t = op.back();
            if (t == 1)
                continue;
            op.pop_back();
            for (;op.size() && pri[op.back()] <= pri[t] && op.back();op.pop_back())
                go(x,op.back());
            op.push_back(t);
        }
    }
    for (;op.size();op.pop_back())
        go(x,op.back());
    assert(x.size() == 1);
    return x[0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << "a&!a";
    for (int i = 0; i < 1024; ++i) {
        if (eval(s,i)) {
            cout << "||";
            for (int j = 0; j < 10; ++j) {
                if (j)
                    cout << '&';
                if (!(i>>j&1))
                    cout << '!';
                cout << char('a'+j);
            }
        }
    }
}
