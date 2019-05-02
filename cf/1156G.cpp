#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int N = 4087;
pair<string,pair<int,int>> var[N];
map<pair<string,pair<int,int>>,int> ivar;
int vn=1;
map<string,int> cur;
vector<string> ans;
string name[N];
set<string> used;
int tp,rt;
int get(string s)
{
    if (!cur.count(s))
        var[cur[s] = vn++] = {s,{0,0}};
    return cur[s];
}
int get_var(pair<string,pair<int,int>> p)
{
    if (!ivar.count(p))
        var[ivar[p] = vn++] = p;
    return ivar[p];
}
string dec(int x)
{
    string ret;
    for (int i=0;i<4;++i)
        ret+=char(x%26+'a'), x/=26;
    return ret;
}
string nxt_name()
{
    while (used.count(dec(tp)))
        tp++;
    return dec(tp++);
}
void go(int u)
{
    if (name[u].size())
        return;
    int l,r;
    tie(l,r) = var[u].S;
    if (l) {
        go(l);
        go(r);
        name[u] = u == rt ? "res" : nxt_name();
        ans.push_back(name[u]+"="+name[l]+var[u].F+name[r]);
    } else {
        name[u] = var[u].F;
//        cerr << u << ' ' << name[u] << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        string s,x,y,z;
        cin >> s;
        char op=0;
        for (int i = 0; i < s.size(); ++i)
            if (!(isalpha(s[i]) || isdigit(s[i])))
                op = s[i], s[i] = ' ';
        stringstream ss(s);
        if (op == '=') {
            ss >> x >> y;
            int a = get(y);
            cur[x] = a;
            used.insert(x);
            used.insert(y);
//            cerr << "get " << y << ' '<< get(y) << endl;
        } else {
            ss >> x >> y >> z;
            int a=get(y);
            int b=get(z);
            auto p=make_pair(string{op},make_pair(a,b));
            cur[x] = get_var(p);
            used.insert(x);
            used.insert(y);
            used.insert(z);
        }
    }
    rt = cur["res"];
    if (!rt) {
        cout << "0\n";
        return 0;
    }
    go(rt);
    if (ans.size()) {
        cout << ans.size() << endl;
        for (auto s : ans)
            cout << s << '\n';
    } else if (var[rt].F != "res") {
        cout << "1\nres=" << var[rt].F <<endl;
    } else {
        cout << "0\n";
    }
}
