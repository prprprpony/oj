#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
int main()
{
	int p,x,y;
	cin >> p >> x >> y;
	int i;
	for (i = -((x-y)/50*50); ; i += 50) {
		int t = (x + i) / 50 % 475;
		for (int j = 0; j < 25; ++j) {
		    t = (t * 96 + 42) % 475;
			if (26 + t == p) {
				cout << (i > 0 ? (i+50)/100 : 0) << endl;
				return 0;
			}
		}
	}
}
