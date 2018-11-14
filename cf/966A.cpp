#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,cl,ce,v;
    cin >> n >> m >> cl >> ce >> v;
    vector<int> vl(cl),ve(ce);
    for (int & x : vl)
        cin >> x;
    for (int & x : ve)
        cin >> x;
    int q;
    cin >> q;
    while (q--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) {
            swap(x1,x2);
            swap(y1,y2);
        }
        int ans = INT_MAX;
        if (x1 == x2) {
            ans = abs(y1-y2);
        } else {
            auto it = lower_bound(begin(ve),end(ve),y1);
            auto jt = lower_bound(begin(vl),end(vl),y1);
            if (it != end(ve))
                ans = min(ans,abs(*it-y1)+abs(*it-y2)+(abs(x2-x1)+v-1)/v);
            if (it != begin(ve)) {
                --it;
                ans = min(ans,abs(*it-y1)+abs(*it-y2)+(abs(x2-x1)+v-1)/v);
            }
            if (jt != end(vl))
                ans = min(ans,abs(*jt-y1)+abs(*jt-y2)+abs(x2-x1));
            if (jt != begin(vl)) {
                --jt;
                ans = min(ans,abs(*jt-y1)+abs(*jt-y2)+abs(x2-x1));
            }
        }
        cout << ans << '\n';
    }
}
