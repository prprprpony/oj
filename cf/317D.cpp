#include<bits/stdc++.h>
using namespace std;
namespace pre {
const int N = 29;
map<int,int> sg;
int gao(int i)
{
    if (sg.count(i))
        return sg[i];
    vector<int> v;
    for (int j = 0; j < N; ++j)
        if (i & (1<<j))
            v.push_back(j+1);
    set<int> mex;
    for (int j : v) {
        int m = 0;
        for (int k : v) {
            if (k % j == 0)
                continue;
            m |= 1<<(k-1);
        }
        mex.insert(gao(m));
    }
    int &s=sg[i];
    s = 0;
    while (mex.count(s))
        ++s;
    return s;
}
void pre()
{
    sg[0] = 0;
    for (int k = 1; k <= N; ++k)
        cout << gao((1<<k)-1) << ',';
}
};
const int sg[] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,};
int main()
{
//    pre::pre();
    int n;
    cin >> n;
    set<int> vis{1};
    int ans=1;
    for (int i = 2; i * i <= n; ++i) {
        if (vis.count(i))
            continue;
        int k = 0;
        for (long long j = i; j <= n; j *= i) {
            vis.insert(j);
            ++k;
        }
        ans ^= sg[k];
    }
    ans ^= (n - vis.size()) % 2 * sg[1];
    cout << (ans ? "Vasya\n" : "Petya\n");
}
