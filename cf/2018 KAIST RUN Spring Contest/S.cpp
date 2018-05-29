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
int r[4], f[4];
map<string,int> fq, la;
const string ans[5][5] = {
{"New Customer","Promising","About to Sleep","Lost","Lost"},
{"Potential Loyalist","Potential Loyalist","About to Sleep","Hibernating","Lost"},
{"Potential Loyalist","Potential Loyalist","Need Attention","About to Leave","About to Leave"},
{ "Loyal Customer","Loyal Customer","Loyal Customer","About to Leave","About to Leave"},
{ "Champion" ,"Loyal Customer","Loyal Customer","About to Leave", "Can't Lose Them" },
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    REP(i,0,4) cin >> r[i];
    REP(i,0,4) cin >> f[i];
    int n;
    cin >> n;
    REP(t,1,n+1) {
        int ty;
        string s;
        cin >> ty >> s;
        if (ty == 1) {
            ++fq[s];
            la[s] = t;
        } else {
            if (!la.count(s)) {
                cout << "None\n";
                continue; 
            }
            int x = t - la[s], y = fq[s];
            x = lower_bound(r,r+4,x) - r;
            y = lower_bound(f,f+4,y) - f;
            cout << ans[y][x] << '\n';
        }
    }
}
