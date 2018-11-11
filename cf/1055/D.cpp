#include<bits/stdc++.h>
#define y0 waserdtfyguygthretwhrtrr
using namespace std;
#define SZ(a) ((int)(a).size())
typedef long long ll;

void build_fail_function(string B, int *fail) {
    int len = B.length(), pos;
    pos = fail[0] = -1;
    for (int i = 1; i < len; i ++) {
        while (pos != -1 and B[pos + 1] != B[i])
            pos = fail[pos];
        if (B[pos + 1] == B[i]) pos ++;
        fail[i] = pos;
    }
}

int match(string A, string B, int *fail) {
    int lenA = A.length(), lenB = B.length();
    int pos = -1;
    for (int i = 0; i < lenA; i ++) {
        while (pos != -1 and B[pos + 1] != A[i])
            pos = fail[pos];

        if (B[pos + 1] == A[i]) pos ++;

        if (pos == lenB - 1) {
            // Match ! A[i - lenB + 1, i] = B
            return i - lenB + 1;
            pos = fail[pos];
        }
    }
    return -1;
}

const int N = 3056;
string s[N],t[N];
int lt[N], rt[N], fail[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    string a(N,'a'),b(N,'b');
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int & fi = lt[i];
        int & la = rt[i];
        fi = N, la = -1;
        for (int j = 0; j < SZ(s[i]); ++j)
            if (s[i][j] != t[i][j]) {
                fi = j;
                break;
            }
        if (fi == N)
            continue;
        v.push_back(i);
        for (int j = SZ(s[i])-1; j >= 0; --j)
            if (s[i][j] != t[i][j]) {
                la = j;
                break;
            }
        if (SZ(a) == N) {
            a = s[i].substr(fi,la-fi+1);
            b = t[i].substr(fi,la-fi+1);
        } else {
            if (a != s[i].substr(fi,la-fi+1) || b != t[i].substr(fi,la-fi+1)) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    int o = v[0];
    bool fl=1;
    while (fl) {
        for (int i : v)
            fl = fl && lt[i]>0 && s[i][lt[i]-1] == s[o][lt[o]-1]
                 && t[i][lt[i]-1] == t[o][lt[o]-1];
        if (fl)
            for (int i : v)
                --lt[i];
    }
    fl=1;
    while (fl) {
        for (int i : v)
            fl = fl && rt[i]+1<SZ(s[i]) && s[i][rt[i]+1] == s[o][rt[o]+1]
                 && t[i][rt[i]+1] == t[o][rt[o]+1];
        if (fl)
            for (int i : v)
                ++rt[i];
    }
    a = s[o].substr(lt[o],rt[o]-lt[o]+1);
    b = t[o].substr(lt[o],rt[o]-lt[o]+1);
    build_fail_function(a, fail);
    for (int i = 0; i < n; ++i) {
        int p = match(s[i],a,fail);
        if (p == -1)
            continue;
        if (lt[i] != p) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n" << a << '\n' << b << '\n';
}
