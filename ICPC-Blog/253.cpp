#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,l,a=0,b=0,c=0;
    cin >> n >> k >> l;
    while (n--) {
        int x,y,z;
        cin >> x >> y >> z;
        a+=x;
        b+=y;
        c+=z;
    }
    priority_queue<int> pl,pr;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        pl.push(x);
    }
    for (int i = 0; i < l; ++i) {
        int x;
        cin >> x;
        pr.push(x);
    }
    int ans = 0;
    for (;pl.size() && a;ans += pl.top(), pl.pop(), --a);
    for (;pr.size() && b;ans += pr.top(), pr.pop(), --b);
    for (;pr.size();pl.push(pr.top()),pr.pop());
    for (;pl.size() && c;ans += pl.top(), pl.pop(), --c);
    cout << ans << endl;
}
