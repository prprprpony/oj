#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
template<class T>
bool cmax(T & a,const T & b) {return a < b ? a = b, 1 : 0;}
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define PER(i,a,b) for (int i((a)-1); i >= (b); --i)
//
const int N = 251234;
pll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    REP(i,0,n) {
        cin >> a[i].F >> a[i].S;
        a[i].F += a[i].S;
    }
    sort(a,a+n);
    ll s = 0;
    priority_queue<ll> pq;
    REP(i,0,n) {
        if (s <= a[i].F - a[i].S) {
            s += a[i].S;
            pq.push(a[i].S);
        } else  if (a[i].S < pq.top() && s - pq.top() <= a[i].F - a[i].S) {
            s += a[i].S - pq.top();
            pq.pop();
            pq.push(a[i].S);
        }
    }
    cout << pq.size() << endl;
}
