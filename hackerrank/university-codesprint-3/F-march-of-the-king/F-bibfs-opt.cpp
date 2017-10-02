#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define F first
#define S second
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PB push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
template<class T,class U>
bool cmax(T & a,const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a,const U & b) {return a > b ? a = b, 1 : 0;}
/* */
const ull I = 1;
char g[9][9];
vector<ull> dp[2][8][8][2];
void bf(int f,string s)
{
	RP(i,8)
		RP(j,8)
			if (g[i][j] == s[0])
				dp[f][i][j][0].PB(I << (i * 8 + j));
	for (int t = 1; t < SZ(s); ++t) {
		RP(i,8)
			RP(j,8) {
				dp[f][i][j][t&1].clear();
				if (g[i][j] == s[t]) {
					ull b = I << (i * 8 + j);
					REP(x,i-1,i+2) if (0 <= x && x < 8)
						REP(y,j-1,j+2) if (0 <= y && y < 8 && !(x == i && y == j)) {
							for (const auto & m : dp[f][x][y][t&1^1])
								if (!(m & b))
									dp[f][i][j][t&1].PB(m | b);
						}
				}
			}
	}
}
#define W 16
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int k;
	string s;
	cin >> k >> s;
	RP(i,8) cin >> g[i];
	const int mi = 7;
	ll ans = 0;
	if (k <= mi)  {
		bf(0,s);
		RP(i,8)
			RP(j,8)
			ans += SZ(dp[0][i][j][k&1^1]);
	} else {
		string t(s.substr(mi,k-mi));
		reverse(ALL(t));
		bf(0,s = s.substr(0,mi));
		bf(1,t);
		RP(i,8)
			RP(j,8)
			for (const auto & u : dp[0][i][j][SZ(s)&1^1])
				REP(x,-1,2) if (0 <= i + x && i + x < 8)
					REP(y,-1,2) if (0 <= j + y && j + y < 8 && (x || y)) {
						const auto & v = dp[1][i+x][j+y][SZ(t)&1^1];
						auto it = v.data();
						int c = SZ(v);
						int n = c / W;
						switch (c % W) {
							case 15: ans += !(u & (*it++));
							case 14: ans += !(u & (*it++));
							case 13: ans += !(u & (*it++));
							case 12: ans += !(u & (*it++));
							case 11: ans += !(u & (*it++));
							case 10: ans += !(u & (*it++));
							case 9: ans += !(u & (*it++));
							case 8: ans += !(u & (*it++));
							case 7: ans += !(u & (*it++));
							case 6: ans += !(u & (*it++));
							case 5: ans += !(u & (*it++));
							case 4: ans += !(u & (*it++));
							case 3: ans += !(u & (*it++));
							case 2: ans += !(u & (*it++));
							case 1: ans += !(u & (*it++));
						}
						while (n--) {
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
							ans += !(u & (*it++));
						}

					}
	}
	/*
	   REP(x,i-1,i+2) if (0 <= x && x < 8)
	   REP(y,j-1,j+2) if (0 <= y && y < 8 && !(x == i && y == j))
	   for (const auto & v : dp[1][x][y][SZ(t)&1^1])
	   ans += !(u & v);
	 */
cout << ans << '\n';
}
