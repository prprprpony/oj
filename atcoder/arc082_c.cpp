#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {return b ? gcd(b,a%b) : abs(a);}
const int N = 205, M = 998244353;
int p2[N];
pair<int,int> a[205];
int main()
{
    int n;
    cin >> n;
    p2[0] = 1;
    for (int i = 1; i <= n; ++i)
        p2[i] = p2[i-1] * 2 % M;
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        map<pair<int,int>,int> mp;
        for (int j = 0; j < i; ++j) {
            pair<int,int> v = {a[j].first - a[i].first, a[j].second - a[i].second};
            if (v.first < 0) {
                v.first *= -1;
                v.second *= -1;
            } else if (v.first == 0 && v.second < 0) {
                v.second *= -1;
            }
            int d = gcd(v.first, v.second);
            v.first /= d;
            v.second /= d;
            ++mp[v];
        }
        ++ans;
        for (auto it = begin(mp); it != end(mp); ++it)
            ans += p2[it->second] + M - 1;
    }
    cout << (p2[n] + M - ans%M) % M << endl; 
}
