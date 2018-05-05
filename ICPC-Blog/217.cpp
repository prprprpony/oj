#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct student {
    string name, score, score_remove_zero;
}p[200000], opt[N];
map<string,int> cnt;
bool cmp(const student & a, const student & b)
{
    ++cnt[a.name];
    ++cnt[b.name];
    return a.name < b.name;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int W = 2e5;
    vector<int> f(N);
    iota(begin(f),end(f),0);
    srand(514);
    random_shuffle(begin(f),end(f));

    string cs;
    for (char c = '0'; c <= '9'; ++c)
        cs += c;
    for (char c = 'a'; c <= 'z'; ++c)
        cs += c;
    for (char c = 'A'; c <= 'Z'; ++c)
        cs += c;
    sort(begin(cs),end(cs));
    for (int i = 0; i < N; ++i)
        for (int j = 0, x = i; j < 3; ++j, x /= cs.size()) 
            p[i].name = cs[x % cs.size()] + p[i].name;
    assert(is_sorted(p,p+N,cmp));
    stable_sort(p,p+N,cmp);
    int mx = 0;
    for (int i = 1; i < N; ++i)
        if (cnt[p[i].name] > cnt[p[mx].name])
            mx = i;
    cerr << "f[mx]=" << f[mx] << ",c(mx)="<< cnt[p[mx].name] << endl;
    assert(cnt[p[mx].name] >= 1e9 / W);

    for (int i = 0; i < N; ++i) {
        opt[f[i]].name = p[i].name;
        if (i != mx)
            opt[f[i]].score = i < mx ? "2." : "0.";
        else {
            opt[f[i]].score = "1.";
            for (int j = 0; j < W; ++j)
                opt[f[i]].score += '8';
        }
    }


    cout << N << '\n';
    for (int i = 0; i < N; ++i)
        cout << opt[i].name + " " + opt[i].score + "\n";
}
